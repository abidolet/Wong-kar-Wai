#include "2048.h"
#include <ncurses.h>

/**
 * @brief Remove zeros from the row and shift non-zero values to the left
 * 
 * @param row	The row of the game board to process
 * @param size	The size of the row
 * @return size_t The number of non-zero values in the row after processing
 */
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

/**
 * @brief Reverse the order of the elements in the row
 * 
 * @param row	The row of the game board to reverse
 * @param size	The size of the row
 */
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

/**
 * @brief Push the non-zero values in the row to the left, merge adjacent equal values, and update the score
 * 
 * @param game	The game structure containing the game state and information for handling input
 * @param row	The row of the game board to process
 */
static void push(t_game* game, size_t* row)
{
	size_t tmp[game->board.size];
	ft_memcpy(tmp, row, game->board.size * sizeof(size_t));	

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

	game->board.moved |= (ft_memcmp(tmp, row, game->board.size * sizeof(size_t)) != 0);
}

/**
 * @brief Get the column object
 * 
 * @param game		The game structure containing the game state and information for handling input
 * @param j			The index of the column to get
 * @param column	The array to store the values of the column
 */
static void	get_column(t_game* game, size_t j, size_t* column)
{
	for (size_t i = 0; i < game->board.size; i++)
	{
		column[i] = game->board.cells[i][j];
	}
}

/**
 * @brief Move the cells up
 * 
 * @param game The game structure containing the game state and information for handling input
 */
static void move_up(t_game* game)
{
	for (size_t j = 0; j < game->board.size; j++)
	{
		size_t column[game->board.size];

		get_column(game, j, column);
		push(game, column);

		for (size_t i = 0; i < game->board.size; i++)
		{
			game->board.cells[i][j] = column[i];
		}
	}
}

/**
 * @brief Move the cells down
 * 
 * @param game The game structure containing the game state and information for handling input
 */
static void move_down(t_game* game)
{
	for (size_t i = 0; i < game->board.size; i++)
	{
		size_t column[game->board.size];

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

/**
 * @brief Move the cells left
 * 
 * @param game The game structure containing the game state and information for handling input
 */
static void move_left(t_game* game)
{
	for (size_t i = 0; i < game->board.size; i++)
	{
		push(game, game->board.cells[i]);
	}
}

/**
 * @brief Move the cells right
 * 
 * @param game The game structure containing the game state and information for handling input
 */
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

/**
 * @brief Move the cells in the direction specified by the user input
 * 
 * @param game The game structure containing the game state and information for handling input
 */
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
