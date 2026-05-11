#include "2048.h"
#include <fcntl.h>
#include <ncurses.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Checks if a number is a power of two
 * 
 * @param n The number to check
 * @return true if the number is a power of two, false otherwise
 */
static bool is_power_of_two(size_t n)
{
	return (n > 0) && ((n & (n - 1)) == 0);
}

/**
 * @brief Initializes the win value for the game
 * 
 * @param game The game structure to initialize
 */
static void init_win_value(t_game* game)
{
	if (is_power_of_two(WIN_VALUE))
	{
		game->board.win_value = WIN_VALUE;
	}
	else
	{
		game->board.win_value = 2048;
	}
}

/**
 * @brief Initializes the colors of the tiles
 * 
 */
static void init_game_colors(void)
{
	for (int i = 1; i <= 26; i++)
	{
		short r = 1000;
		short g = 1000 - (i * 80);
		short b = 1000 - (i * 150);

		init_color(100 + i, r, g, b);
		init_pair(i, COLOR_BLACK, 100 + i);
	}
}

/**
 * @brief Initializes the curses library
 *
 */
static void init_curses(void)
{
	initscr();
	start_color();
	init_game_colors();
	init_pair(100, COLOR_BLACK, COLOR_WHITE);
	curs_set(0);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	timeout(100);
}

/**
 * @brief Initializes the game
 * 
 * @param game The game structure to initialize
 */
void init(t_game* game)
{
	init_curses();
	init_win_value(game);
	game->state = MENU;
	draw(game);
}
