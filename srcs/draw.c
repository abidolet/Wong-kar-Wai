#include "2048.h"
#include <curses.h>

void	get_skeleton_raw(int x, int start_x, int start_y, int h, int tot_h, bool border)
{
	int	y;

	y = 0;
	while (y < tot_h)
	{
		if (y % (h + 1) == 0)
			if (border)
				mvaddch(start_y + y, start_x + x, '+');
			else
				mvaddch(start_y + y, start_x + x, '-');
		else
			if (border)
				mvaddch(start_y + y, start_x + x, '|');
			else
				mvaddch(start_y + y, start_x + x, ' ');
		y++;
	}
}

void	get_skeleton_line(t_board *board, int h, int l)
{
	int		x;
	int 	max_x;
	int 	max_y;
	int		tot_w;
	int		tot_h;
	int		start_x;
	int		start_y;

	getmaxyx(stdscr, max_y, max_x);
	tot_w = l * board->size + board->size + 1;
	tot_h = h * board->size + board->size + 1;
	start_x = (max_x - tot_w) / 2;
	start_y = (max_y - tot_h) / 2;

	x = 0;
	while (x < tot_w)
	{
		if (x % (l + 1) == 0)
			get_skeleton_raw(x, start_x, start_y, h, tot_h, 1);
		else
			get_skeleton_raw(x, start_x, start_y, h, tot_h, 0);
		x++;
	}
}

void	draw(t_game *game)
{
	if (game->state != PLAYING)
	{
		new_game(game);
	}
	else
	{
		update(game);
	}
}
