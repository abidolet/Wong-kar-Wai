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
    mvprintw(cell_y, cell_x, "%zu", l, board->cells[i][j]);

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

void	draw(t_game* game)
{
	int	l = 8;
	int	h = 5;
	int	max_x;
	int	max_y;
	int	tot_w;
	int	tot_h;
	int	start_x;
	int	start_y;

	// new_game(game);
	iter_board(game, bitboard_to_grid);

	getmaxyx(stdscr, max_y, max_x);
	tot_w = l * game->board.size + game->board.size + 1;
	tot_h = h * game->board.size + game->board.size + 1;

	clear();

	if (max_x < tot_w || max_y < tot_h + 2)
		mvprintw(max_y / 2, (max_x - 18) / 2, "Terminal too small");
	else
	{
		start_x = (max_x - tot_w) / 2;
		start_y = (max_y - tot_h) / 2;

		if (start_y < 2)
			start_y = 2;

		get_skeleton_line(start_x, start_y, h, l, tot_h, tot_w);
		fill_cells(&game->board, start_x, start_y, h, l);
	}
}
