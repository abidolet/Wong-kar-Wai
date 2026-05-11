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
