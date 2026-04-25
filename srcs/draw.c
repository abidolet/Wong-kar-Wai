#include "2048.h"

void	draw(t_game *game)
{
	if (game->state != PLAYING)
	{
		new_game(game);
	}
	else
	{
		update(game);
	}
}
