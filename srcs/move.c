#include "2048.h"
#include <ncurses.h>

static size_t unique(size_t* row, size_t size)
{
	size_t k = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (row[i] != 0)
		{
			row[k] = row[i];
			k++;
		}
	}
	return k;
}

static void reverse(size_t* row, size_t size)
{
	size_t temp;

	for (size_t i = 0; i < size / 2; i++)
	{
		temp = row[i];
		row[i] = row[size - 1 - i];
		row[size - 1 - i] = temp;
	}
}

static void push(t_game* game, size_t* row)
{
	size_t k = unique(row, game->board.size);
	ft_bzero(&row[k], (game->board.size - k) * sizeof(size_t));

	for (size_t j = 1; j < k; j++)
	{
		if (row[j] == row[j - 1])
		{
			row[j - 1] *= 2;
			game->board.score += row[j - 1];
			row[j] = 0;
			j++;
		}
	}

	k = unique(row, game->board.size);
	ft_bzero(&row[k], (game->board.size - k) * sizeof(size_t));
}

static void	get_column(t_game* game, size_t j, size_t* column)
{
	for (size_t i = 0; i < game->board.size; i++)
	{
		column[i] = game->board.cells[i][j];
	}
}

static void move_up(t_game* game)
{
	for (size_t j = 0; j < game->board.size; j++)
	{
		size_t column[4];

		get_column(game, j, column);
		push(game, column);

		for (size_t i = 0; i < game->board.size; i++)
		{
			game->board.cells[i][j] = column[i];
		}
	}
}

static void move_down(t_game* game)
{
	for (size_t i = 0; i < game->board.size; i++)
	{
		size_t column[4];

		get_column(game, i, column);
		reverse(column, game->board.size);
		push(game, column);
		reverse(column, game->board.size);

		for (size_t j = 0; j < game->board.size; j++)
		{
			game->board.cells[j][i] = column[j];
		}
	}
}

static void move_left(t_game* game)
{
	for (size_t i = 0; i < game->board.size; i++)
	{
		push(game, game->board.cells[i]);
	}
}

static void move_right(t_game* game)
{
	for (size_t i = 0; i < game->board.size; i++)
	{
		size_t* row = game->board.cells[i];
		reverse(row, game->board.size);
		push(game, row);
		reverse(row, game->board.size);
	}
}

void move_cells(t_game* game)
{
	switch (game->key)
	{
	case KEY_UP:
		move_up(game);
		break;
	case KEY_DOWN:
		move_down(game);
		break;
	case KEY_LEFT:
		move_left(game);
		break;
	case KEY_RIGHT:
		move_right(game);
		break;
	}
}
