#include "2048.h"
#include <curses.h>

int		get_color_id(size_t value)
{
    int	power;
    
    power = 0;
    while (value > 1)
    {
        value >>= 1;
        power++;
    }

    if (power > 17)
        return (17);
    return (power);
}

void	get_skeleton_raw(int x, int start_x, int start_y, int h, int tot_h,
					  bool border)
{
	int	y;

	y = 0;
	while (y < tot_h)
	{
		if (y % (h + 1) == 0)
		{
			if (border)
				mvaddch(start_y + y, start_x + x, '+');
			else
				mvaddch(start_y + y, start_x + x, '-');
		}
		else if (border)
			mvaddch(start_y + y, start_x + x, '|');
		else
			mvaddch(start_y + y, start_x + x, ' ');
		y++;
	}
}

void	get_skeleton_line(int start_x, int start_y, int h, int l, int tot_h,
					   int tot_w)
{
	int	x;

	attron(COLOR_PAIR(100));
	x = 0;
	while (x < tot_w)
	{
		if (x % (l + 1) == 0)
			get_skeleton_raw(x, start_x, start_y, h, tot_h, 1);
		else
			get_skeleton_raw(x, start_x, start_y, h, tot_h, 0);
		x++;
	}
	attroff(COLOR_PAIR(100));
}

void	draw_single_cell(t_board *board, int i, int j, int start_x, int start_y, int h, int l)
{
    int		color_id;
    int		dy;
    int		dx;
    int		cell_y;
    int		cell_x;
	int		num_len;
	size_t	temp;

    color_id = get_color_id(board->cells[i][j]);
    attron(COLOR_PAIR(color_id));

    dy = 0;
    while (dy < h)
    {
        dx = 0;
        while (dx < l)
        {
            mvaddch(start_y + i * (h + 1) + 1 + dy, start_x + j * (l + 1) + 1 + dx, ' ');
            dx++;
        }
        dy++;
    }

	num_len = 0;
    temp = board->cells[i][j];
    while (temp > 0)
    {
        temp /= 10;
        num_len++;
    }

    cell_y = start_y + i * (h + 1) + 1 + (h / 2);
    cell_x = start_x + j * (l + 1) + 1;
    mvprintw(cell_y, cell_x, "%zu", board->cells[i][j]);

    attroff(COLOR_PAIR(color_id));
}

void	fill_cells(t_board* board, int start_x, int start_y, int h, int l)
{
	size_t	i;
	size_t	j;

	mvprintw(start_y - 2, start_x, "Score : %u", board->score);

	i = 0;
	while (i < board->size)
	{
		j = 0;
		while (j < board->size)
		{
			if (board->cells[i][j] != 0)
				draw_single_cell(board, i, j, start_x, start_y, h, l);
			j++;
		}
		i++;
	}
}

void draw_game(t_draw* draw, t_board* board)
{
	draw->l = 8;
	draw->h = 5;

	draw->tot_w = draw->l * board->size + board->size + 1;
	draw->tot_h = draw->h * board->size + board->size + 1;
	if (draw->max_x < draw->tot_w || draw->max_y < draw->tot_h + 2)
	{
		mvprintw(draw->max_y / 2, (draw->max_x - 18) / 2, "Terminal too small");
		return ;
	}

	draw->start_x = (draw->max_x - draw->tot_w) / 2;
	draw->start_y = (draw->max_y - draw->tot_h) / 2;

	if (draw->start_y < 2)
		draw->start_y = 2;
	get_skeleton_line(draw->start_x, draw->start_y, draw->h, draw->l, draw->tot_h, draw->tot_w);
	fill_cells(board, draw->start_x, draw->start_y, draw->h, draw->l);
}

static bool is_terminal_too_small(t_draw* draw)
{
	return (draw->max_x < draw->tot_w || draw->max_y < draw->tot_h + 2);
}

static void draw_end(t_game* game)
{
	
	if (game->state & WIN)
	{
		printw("You won! But you cannot continue playing!");
		// the user has won the game but cannot continue playing, so we show the win screen
	}
	else
	{
		printw("You lose!");
		// the user has lost the game, so we show the game over screen
	}

	game->state = MENU;
}

static void draw_win(t_game* game)
{
	printw("You won!");	

	// user must decide either return to the menu or continue the game

	// if the user wants to return to the menu
	game->state = MENU;

	// if the user wants to continue the game
	game->state |= PLAYING;
}

static void draw_leaderboard(t_game* game)
{
	// TODO

	// need to add an option to come back to the menu from the leaderboard

	// if the user wants to come back to the menu
	game->state = MENU;
}

static void draw_menu(t_game* game)
{
	static int selected_option = 0;

	if (game->key == KEY_UP)
	{
		selected_option = (selected_option - 1 + 3) % 3;
	}
	else if (game->key == KEY_DOWN)
	{
		selected_option = (selected_option + 1) % 3;
	}
	else if (game->key == KEY_ENTER || game->key == '\n'  || game->key == '\r')
	{
		if (selected_option == 0)
		{
			new_game(game);
			draw_game(&game->draw, &game->board);
			return ;
		}
		else if (selected_option == 1)
		{
			game->state = LEADERBOARD;
		}
		else
		{
			game->key = KEY_ESCAPE;
		}
	}

	// need to draw the menu options
	mvprintw(game->draw.max_y / 2 - 1, (game->draw.max_x - 16) / 2, "Start New Game");
	mvprintw(game->draw.max_y / 2, (game->draw.max_x - 16) / 2, "View Leaderboard");
	mvprintw(game->draw.max_y / 2 + 1, (game->draw.max_x - 16) / 2, "Exit");

	// highlight the selected option
}

void	draw(t_game* game)
{
	t_board* board = &game->board;
	t_draw* draw = &game->draw;

	clear();

	getmaxyx(stdscr, draw->max_y, draw->max_x);
	draw->l = 8;
	draw->h = 5;
	draw->tot_w = draw->l * game->board.size + game->board.size + 1;
	draw->tot_h = draw->h * game->board.size + game->board.size + 1;

	ft_dprintf(2, "Game state: %u\n", game->state);

	clear();

	if (is_terminal_too_small(draw))
	{
		mvprintw(draw->max_y / 2, (draw->max_x - 18) / 2, "Terminal too small");
	}
	else if (game->state & MENU)
	{
		draw_menu(game);
	}
	else if (game->state & LEADERBOARD)
	{
		draw_leaderboard(game);
	}
	else if (game->state & WIN && !(game->state & PLAYING))
	{
		draw_win(game);
	}
	else if (game->state & PLAYING)
	{
		draw_game(draw, board);
	}
	else
	{
		draw_end(game);
	}

	refresh();
}

void resize(t_game* game)
{
	endwin();
	refresh();
	clear();
	draw(game);
	refresh();
}
