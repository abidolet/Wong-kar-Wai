#include "2048.h"

/**
 * @brief Iterates over each cell in the board and applies the given function to it.
 * 
 * @param game The game instance.
 * @param func The function to apply to each cell.
 */
void iter_board(t_game* game, void (*func)(t_game*, size_t, size_t))
{
	for (size_t i = 0; i < game->board.size; i++)
	{
		for (size_t j = 0; j < game->board.size; j++)
		{
			func(game, i, j);
		}
	}
}

/**
 * @brief Converts the bitboard representation to the grid representation.
 * 
 * @param game The game instance.
 * @param i The row index.
 * @param j The column index.
 */
void bitboard_to_grid(t_game* game, size_t i, size_t j)
{
	t_board* board;
	int shift;
	uint64_t exponent;

	board = &game->board;
	shift = (i * 4 + j) * 4;
	exponent = (board->bitboard >> shift) & 0xF;
	board->cells[i][j] = (exponent == 0) ? 0 : (size_t)1 << exponent;
}

/**
 * @brief Get the exponent object
 * 
 * @param val The value to calculate the exponent for.
 * @return uint64_t The exponent of the value.
 */
static uint64_t get_exponent(size_t val)
{
	if (val == 0)
	{
		return 0;
	}

	uint64_t exp = 0;
	while (val > 1)
	{
		val >>= 1;
		exp++;
	}

	return exp;
}

/**
 * @brief Converts the grid representation to the bitboard representation.
 * 
 * @param game The game instance.
 * @param i The row index.
 * @param j The column index.
 */
void grid_to_bitboard(t_game* game, size_t i, size_t j)
{
	t_board* board;
	int shift;
	uint64_t exponent;

	board = &game->board;
	shift = (i * 4 + j) * 4;
	exponent = get_exponent(board->cells[i][j]);
	board->bitboard |= (exponent << shift);
}
