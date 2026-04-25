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

void	get_skeleton_line(int start_x, int start_y, int h, int l, int tot_h, int tot_w)
{
	int		x;

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

void    fill_cells(t_board *board, int start_x, int start_y, int h, int l)
{
    size_t i;
    size_t j;
    int cell_y;
    int cell_x;

    mvprintw(start_y - 2, start_x, "Score : %zu", board->score);

    i = 0;
    while (i < board->size)
    {
        j = 0;
        while (j < board->size)
    	{
            if (board->cells[i][j] != 0)
            {
                cell_y = start_y + i * (h + 1) + 1 + (h / 2);
                cell_x = start_x + j * (l + 1) + 1;
                
                mvprintw(cell_y, cell_x, "%*zu", l, board->cells[i][j]);
            }
            j++;
        }
        i++;
    }
}

void	draw(t_game *game)
{
	int 	l = 8;
    int 	h = 5;
	int 	max_x;
	int 	max_y;
	int		tot_w;
	int		tot_h;
	int		start_x;
	int		start_y;

	if (game->state != PLAYING)
	{
		new_game(game);
	}

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
