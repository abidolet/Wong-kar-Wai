#include "2048.h"

void	print_board(t_game *game)
{
	for (size_t i = 0; i < game->size; i++)
	{
		for (size_t j = 0; j < game->size; j++)
		{
			if (game->board[i][j] == 0)
				ft_dprintf(2, ". ");
			else
				ft_dprintf(2, "%zu ", game->board[i][j]);
		}
		ft_dprintf(2, "\n");
	}
}

void	update(t_game *game)
{
	ft_dprintf(2, "Score: %zu\n", game->score);
	print_board(game);
	ft_dprintf(2, "\n");
	(void)game;
}

void	new_game(t_game *game)
{
	(void)game;
}
