#include "2048.h"
#include <ncurses.h>
#include <stdlib.h>

static void get_random_cell(t_game* game, size_t i, size_t j)
{
	if (game->board.cells[i][j] == 0)
	{
		game->board.empty_cells++;
		if (rand() % game->board.empty_cells == 0)
		{
			game->board.x = i;
			game->board.y = j;
		}
	}
}

static void add_number(t_game* game)
{
	game->board.empty_cells = 0;
	iter_board(game, get_random_cell);
	int value = (rand() % 10 == 0) ? 4 : 2;
	game->board.cells[game->board.x][game->board.y] = value;
}

void update(t_game* game)
{
	move_cells(game);
	add_number(game);
}

void new_game(t_game* game)
{
	ft_bzero(&game->board, sizeof(t_board));
	game->board.size = 4;
	game->state = PLAYING;
	add_number(game);
	add_number(game);
}
