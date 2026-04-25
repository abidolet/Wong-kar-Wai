#include "2048.h"

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

void	bitboard_to_grid(t_game* game, size_t i, size_t j)
{
	t_board*	board;
	int			shift; 
	uint64_t	exponent;

	board = &game->board;
	shift = (i * 4 + j) * 4;
	exponent = (board->bitboard >> shift) & 0xF;
	board->cells[i][j] = (exponent == 0) ? 0 : (size_t)1 << exponent;
}

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

void	grid_to_bitboard(t_game* game, size_t i, size_t j)
{
	t_board*	board;
	int			shift;
	uint64_t	exponent;

	board = &game->board;
	shift = (i * 4 + j) * 4;
	exponent = get_exponent(board->cells[i][j]);
	board->bitboard |= (exponent << shift);
}
