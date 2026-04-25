#include "2048.h"
#include <ncurses.h>

bool is_arrow_key(int key)
{
	return (key == KEY_DOWN || key == KEY_UP
			|| key == KEY_LEFT || key == KEY_RIGHT);
}

void draw(t_game* game)
{
	if (is_arrow_key(game->key))
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
}
