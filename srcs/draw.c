#include "2048.h"
#include <curses.h>
#include <stdlib.h>

/**
 * @brief Get the color id object
 * 
 * @param value The value of the cell to determine the color
 * @return int The color id corresponding to the cell value
 */
int get_color_id(size_t value)
{
	int power;

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

/**
 * @brief Get the skeleton raw object
 * 
 * @param x			The x coordinate of the raw to get
 * @param start_x	The x coordinate of the top left corner of the frame
 * @param start_y	The y coordinate of the top left corner of the frame
 * @param h			The height of each cell
 * @param tot_h		The total height of the frame
 * @param border	Whether to draw borders
 */
void get_skeleton_raw(int x, int start_x, int start_y, int h, int tot_h,
					  bool border)
{
	int y;

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

/**
 * @brief Get the skeleton line object
 * 
 * @param start_x	The x coordinate of the top left corner of the frame
 * @param start_y	The y coordinate of the top left corner of the frame
 * @param h			The height of each cell
 * @param l			The width of each cell
 * @param tot_h		The total height of the frame
 * @param tot_w		The total width of the frame
 */
void get_skeleton_line(int start_x, int start_y, int h, int l, int tot_h,
					   int tot_w)
{
	int x;

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

/**
 * @brief Draw a single cell on the screen
 * 
 * @param board		The game board containing the cell values
 * @param i			The row index of the cell to draw
 * @param j			The column index of the cell to draw
 * @param start_x	The x coordinate of the top left corner of the frame
 * @param start_y	The y coordinate of the top left corner of the frame
 * @param h			The height of each cell
 * @param l			The width of each cell
 */
void draw_single_cell(t_board* board, int i, int j, int start_x, int start_y,
					  int h, int l)
{
	int color_id;
	int dy;
	int dx;
	int cell_y;
	int cell_x;
	int num_len;
	size_t temp;

	color_id = get_color_id(board->cells[i][j] + 1);
	attron(COLOR_PAIR(color_id));

	dy = 0;
	while (dy < h)
	{
		dx = 0;
		while (dx < l)
		{
			mvaddch(start_y + i * (h + 1) + 1 + dy,
					start_x + j * (l + 1) + 1 + dx, ' ');
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
	cell_x = start_x + j * (l + 1) + 1 + ((l - num_len) / 2);

	size_t value = board->cells[i][j];
	mvprintw(cell_y, cell_x, "%zu", value);

	attroff(COLOR_PAIR(color_id));
}

/**
 * @brief	Fill the cells of the game board on the screen
 * 
 * @param board		The game board containing the cell values
 * @param start_x	The x coordinate of the top left corner of the frame
 * @param start_y	The y coordinate of the top left corner of the frame
 * @param h			The height of each cell
 * @param l			The width of each cell
 */
void fill_cells(t_board* board, int start_x, int start_y, int h, int l)
{
	size_t i;
	size_t j;

	mvprintw(start_y - 2, start_x, "Score : %zu", board->score);

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

/**
 * @brief Draw the game board on the screen
 * 
 * @param draw	The draw structure containing the draw information
 * @param board	The game board containing the cell values and score
 */
void draw_game(t_draw* draw, t_board* board)
{
	draw->start_x = (draw->max_x - draw->tot_w) / 2;
	draw->start_y = (draw->max_y - draw->tot_h) / 2;

	if (draw->start_y < 2)
		draw->start_y = 2;

	get_skeleton_line(draw->start_x, draw->start_y, draw->h, draw->l,
					  draw->tot_h, draw->tot_w);
	fill_cells(board, draw->start_x, draw->start_y, draw->h, draw->l);
}

/**
 * @brief Check if the terminal is too small to display the game
 * 
 * @param draw	The draw structure containing the draw information and the terminal dimensions
 * @return true if the terminal is too small to display the game,
 * @return false otherwise
 */
static bool is_terminal_too_small(t_draw* draw)
{
	return (draw->max_x < draw->tot_w || draw->max_y < draw->tot_h + 2);
}

/**
 * @brief Draw the game on the screen
 * 
 * @param game The game structure containing the game state and information for drawing
 */
void draw(t_game* game)
{
	t_board* board = &game->board;
	t_draw* draw = &game->draw;

	clear();

	getmaxyx(stdscr, draw->max_y, draw->max_x);
	if (game->board.size > 0)
	{
		draw->l = (draw->max_x - game->board.size - 1) / game->board.size;
		draw->h = (draw->max_y - 2 - game->board.size - 1) / game->board.size;

		if (draw->l < 15)
			draw->l = 15;
		if (draw->h < 7)
			draw->h = 7;

		draw->tot_w = draw->l * game->board.size + game->board.size + 1;
		draw->tot_h = draw->h * game->board.size + game->board.size + 1;
	}
	else
	{
		draw->tot_w = 40;
		draw->tot_h = 20;
	}

	if (game->key == KEY_BACKSPACE)
	{
		game->state = MENU;
	}

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
		draw_win_screen(game);
	}
	else if (game->state & PLAYING)
	{
		draw_game(draw, board);
	}
	else
	{
		draw_end_screen(game);
	}

	refresh();
}

/**
 * @brief Resize the terminal and redraw the game
 * 
 * @param game The game structure containing the game state and information for drawing
 */
void resize(t_game* game)
{
	endwin();
	refresh();
	clear();
	draw(game);
	refresh();
}
