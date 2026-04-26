#include "2048.h"
#include <ncurses.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Reverses the order of the four nibbles in a 16-bit value
 * 
 * @param line The line to reverse
 * @return uint16_t The reversed line
 */
static uint16_t reverse_line(uint16_t line)
{
	return ((line >> 12) & 0x000F) | ((line >> 4) & 0x00F0)
		   | ((line << 4) & 0x0F00) | ((line << 12) & 0xF000);
}

/**
 * @brief Initializes the lookup tables for the game board
 * 
 * @param board The game board to initialize
 */
static void init_tables(t_board* board)
{
	uint16_t* lut_left = board->lut_left;

	for (uint32_t i = 0; i <= UINT16_MAX; i++)
	{
		uint16_t line[4];
		uint32_t score = 0;

		for (size_t j = 0; j < 4; j++)
		{
			line[j] = (i >> (j * 4)) & 0xF;
		}

		for (size_t j = 0; j < 3; j++)
		{
			int next;

			for (next = j + 1; next < 4; next++)
			{
				if (line[next] != 0)
				{
					break;
				}
			}

			if (next == 4)
			{
				break;
			}

			if (line[j] == 0)
			{
				line[j] = line[next];
				line[next] = 0;
				j--;
			}
			else if (line[j] == line[next] && line[j] < 0xF)
			{
				line[j]++;
				line[next] = 0;
				score += (1 << line[j]);
			}
		}

		lut_left[i] = (line[0] << 0) | (line[1] << 4) | (line[2] << 8)
					  | (line[3] << 12);
		board->lut_score[i] = score;
	}

	for (uint32_t i = 0; i <= UINT16_MAX; i++)
	{
		board->lut_right[i] = reverse_line(board->lut_left[reverse_line(i)]);
	}
}

static bool is_power_of_two(size_t n)
{
	return (n > 0) && ((n & (n - 1)) == 0);
}

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

	ft_dprintf(2, "Win value set to %zu\n", game->board.win_value);
}

/**
 * @brief Initializes the colors of the tiles
 * 
 */
static void init_game_colors(void)
{
    // init_pair(PAIR_ID, TEXT_COLOR, BACKGROUND_COLOR);
    
	init_pair(100, COLOR_BLACK, COLOR_WHITE);

    init_pair(1, COLOR_WHITE, COLOR_CYAN);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);
    init_pair(3, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(4, COLOR_WHITE, COLOR_GREEN);
    init_pair(5, COLOR_WHITE, COLOR_YELLOW);
    init_pair(6, COLOR_WHITE, COLOR_RED);

    init_pair(7, COLOR_BLACK, COLOR_CYAN);
    init_pair(8, COLOR_BLACK, COLOR_BLUE);
    init_pair(9, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(10, COLOR_BLACK, COLOR_GREEN);
    init_pair(11, COLOR_BLACK, COLOR_YELLOW); // 2048 !
    init_pair(12, COLOR_BLACK, COLOR_RED);

    init_pair(13, COLOR_YELLOW, COLOR_CYAN);
    init_pair(14, COLOR_YELLOW, COLOR_BLUE);
    init_pair(15, COLOR_YELLOW, COLOR_MAGENTA);
    init_pair(16, COLOR_YELLOW, COLOR_GREEN);
    init_pair(17, COLOR_YELLOW, COLOR_RED);
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
	curs_set(0);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	timeout(100);
}

void init(t_game *game)
{
	init_curses();
	init_win_value(game);
	init_tables(&game->board);
	game->state = MENU;
	draw(game);
}
