#include "2048.h"
#include <curses.h>

void draw_menu(t_game* game)
{
	t_draw* draw = &game->draw;
	const char *options[4] = {"Start Game", "Leaderboard", "Exit"};
	static int selected_option = 0;

	if (game->key == KEY_UP)
	{
		selected_option = (selected_option - 1 + 3) % 3;
	}
	else if (game->key == KEY_DOWN)
	{
		selected_option = (selected_option + 1) % 3;
	}
	else if (game->key == KEY_ENTER || game->key == '\n' || game->key == '\r')
	{
		if (selected_option == 0)
		{
			new_game(game);
			draw_game(&game->draw, &game->board);
			return;
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

	int center_x = draw->max_x / 2;
	int center_y = draw->max_y / 2;

	mvprintw(center_y - 4, center_x - 11, "=== WELCOME TO 2048 ===");
	mvprintw(center_y - 2, center_x - 8, "Please Choose an option");

	for (int i = 0; i < 3; i++)
	{
		if (selected_option == i)
		{
			attron(A_REVERSE);
		}

		mvprintw(center_y + i * 2, center_x - 8, "%s", options[i]);

		if (selected_option == i)
		{
			attroff(A_REVERSE);
		}
	}
}
