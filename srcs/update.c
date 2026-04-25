#include "2048.h"
#include <ncurses.h>
#include <stdlib.h>

static void print_board(t_game* game, size_t i, size_t j)
{
	if (game->board.cells[i][j] == 0)
		printw("  .  ");
	else
		printw("  %zu  ", game->board.cells[i][j]);
	if (j == game->board.size - 1)
		printw("\n");
}

int get_empty_cells(uint64_t board, size_t *empty_cells)
{
	size_t	count = 0;

	for (size_t i = 0; i < 16; i++)
	{
		if (((board >> (i * 4)) & 0xF) == 0)
		{
			empty_cells[count++] = i;
		}
	}

	return count;
}

static void	add_number(uint64_t *board)
{
	size_t		empty_cells[16];
	size_t		count;
	size_t		random_idx;
	uint64_t	tile;

	count = get_empty_cells(*board, empty_cells);
	random_idx = empty_cells[rand() % count];
	tile = (rand() % 10 == 0) ? 2 : 1;

	*board = *board | (tile << ((u_int64_t)random_idx * 4));
}

void update(t_game* game)
{
	uint64_t new_board = move_cells(game);

	if (new_board != game->board.bitboard)
	{
		game->board.bitboard = new_board;
		add_number(&game->board.bitboard);
	}

	iter_board(game, bitboard_to_grid);
	printw("Score: %u\n", game->board.score);
	iter_board(game, print_board);
}

void new_game(t_game* game)
{
	game->board.size = 4;
	game->state = PLAYING;

	add_number(&game->board.bitboard);
	add_number(&game->board.bitboard);

	iter_board(game, bitboard_to_grid);
	printw("Score: %u\n", game->board.score);
	iter_board(game, print_board);
}
