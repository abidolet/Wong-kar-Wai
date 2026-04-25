#include "2048.h"
#include <ncurses.h>
#include <stdlib.h>

/**
 * @brief Get the empty cells object
 * 
 * @param board The game board
 * @param empty_cells An array to store the indices of empty cells
 * @return int The number of empty cells
 */
int get_empty_cells(uint64_t board, size_t* empty_cells)
{
	size_t count = 0;

	for (size_t i = 0; i < 16; i++)
	{
		if (((board >> (i * 4)) & 0xF) == 0)
		{
			empty_cells[count++] = i;
		}
	}

	return count;
}

/**
 * @brief Adds a new number to the game board
 * 
 * @param board The game board
 */
static void add_number(uint64_t* board)
{
	size_t empty_cells[16];
	size_t count;
	size_t random_idx;
	uint64_t tile;

	count = get_empty_cells(*board, empty_cells);
	random_idx = empty_cells[rand() % count];
	tile = (rand() % 10 == 0) ? 2 : 1;

	*board = *board | (tile << ((u_int64_t)random_idx * 4));
}

/**
 * @brief Updates the game state
 * 
 * @param game The game instance
 */
void update(t_game* game)
{
	uint64_t new_board = move_cells(game);

	if (new_board != game->board.bitboard)
	{
		game->board.bitboard = new_board;
		add_number(&game->board.bitboard);
	}
}

/**
 * @brief Starts a new game
 * 
 * @param game The game instance
 */
void new_game(t_game* game)
{
	game->board.size = 4;
	game->state = PLAYING;

	add_number(&game->board.bitboard);
	add_number(&game->board.bitboard);
}
