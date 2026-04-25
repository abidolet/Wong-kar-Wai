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
