#include "2048.h"
#include <curses.h>

/**
 * @brief Draws the main menu
 * 
 * @param game The game structure containing the draw information and the selected button index
 */
void draw_menu(t_game* game)
{
	t_draw* draw = &game->draw;
	const char* options[4]
		= {"Play 4 * 4", "Play 5 * 5", "Leaderboard", "Exit"};
	int center_x = draw->max_x / 2;
	int center_y = draw->max_y / 2;

	mvprintw(center_y - 4, center_x - 8, "=== WELCOME TO 2048 ===");
	mvprintw(center_y - 2, center_x - 8, "Please Choose an option");

	for (size_t i = 0; i < sizeof(options) / sizeof(options[0]); i++)
	{
		if (game->selected_button == i)
			attron(A_REVERSE);

		mvprintw(center_y + i * 2, center_x - 6, "%s", options[i]);

		if (game->selected_button == i)
			attroff(A_REVERSE);
	}
}

/**
 * @brief Draws the end screen
 * 
 * @param game The game structure containing the draw information and the selected button index
 */
void draw_end_screen(t_game* game)
{
	int center_x;
	int center_y;
	unsigned int max_score;

	center_x = game->draw.max_x / 2;
	center_y = game->draw.max_y / 2;

	max_score = (game->board.size == 5) ? MAX_SCORE_5 : MAX_SCORE_4;

	if (game->board.score == max_score)
	{
		attron(COLOR_PAIR(11));
		mvprintw(center_y - 4, center_x - 13, "=== YOU BEAT THE GAME ===");
		attroff(COLOR_PAIR(11));
	}
	else
	{
		attron(COLOR_PAIR(12));
		mvprintw(center_y - 4, center_x - 8, "=== GAME OVER ===");
		attroff(COLOR_PAIR(12));
	}

	mvprintw(center_y - 2, center_x - 10, "Final Score : %zu",
			 game->board.score);
	mvprintw(center_y + 1, center_x - 13, "Press ENTER to return to Menu");

	if (game->selected_button == 0)
		attron(A_REVERSE);
	mvprintw(center_y + 4, center_x - 9, "[ Return to Menu ]");
	if (game->selected_button == 0)
		attroff(A_REVERSE);
}

/**
 * @brief Draws the win screen
 * 
 * @param game The game structure containing the draw information and the selected button index
 */
void draw_win_screen(t_game* game)
{
	int center_x;
	int center_y;

	center_x = game->draw.max_x / 2;
	center_y = game->draw.max_y / 2;

	mvprintw(center_y - 4, center_x - 12, "=== CONGRATULATIONS! ===");
	mvprintw(center_y - 2, center_x - 17, "You reached %zu. Continue playing?",
			 game->board.win_value);

	if (game->selected_button == 0)
		attron(A_REVERSE);
	mvprintw(center_y + 1, center_x - 7, "[   YES   ]");
	if (game->selected_button == 0)
		attroff(A_REVERSE);

	if (game->selected_button == 1)
		attron(A_REVERSE);
	mvprintw(center_y + 3, center_x - 7, "[   NO    ]");
	if (game->selected_button == 1)
		attroff(A_REVERSE);
}
