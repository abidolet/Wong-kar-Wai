#include "2048.h"

void	draw(t_game *game)
{
	if (game->state == PLAYING)
	{
		update(game);
	}
}
