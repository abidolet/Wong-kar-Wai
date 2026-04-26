#include "2048.h"
#include <curses.h>

void	draw_menu(t_game *game, int max_x, int max_y)
{
	int	center_x;
	int	center_y;

	center_x = max_x / 2;
	center_y = max_y / 2;

	mvprintw(center_y - 4, center_x - 11, "=== WELCOME TO 2048 ===");
	mvprintw(center_y - 2, center_x - 8, "Choose grid size");

	if (game->selected_button == 0)
		attron(A_REVERSE);
	mvprintw(center_y, center_x - 5, "[  4 x 4  ]");
	if (game->selected_button == 0)
		attroff(A_REVERSE);

	if (game->selected_button == 1)
		attron(A_REVERSE);
	mvprintw(center_y + 2, center_x - 5, "[  5 x 5  ]");
	if (game->selected_button == 1)
		attroff(A_REVERSE);
}

// void	draw_win_screen(t_game *game, int max_x, int max_y)
// {
// 	;
// }

// void	draw_end_screen(t_game *game, int max_x, int max_y)
// {
// 	;
// }
