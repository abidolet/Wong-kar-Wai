#include "2048.h"
#include <ncurses.h>
#include <stdlib.h>

/**
 * @brief Count the number of empty cells in the game board
 * 
 * @param gameThe	game structure containing the game state and information for handling input
 * @param i			The row index
 * @param j			The column index
 */
static void count_empty_cells(t_game* game, size_t i, size_t j)
{
	if (game->board.cells[i][j] == 0)
	{
		game->board.empty_cells++;
	}
}

/**
 * @brief Check if the game board is empty
 * 
 * @param game	The game structure containing the game state and information for handling input
 * @return true If the game board is empty,
 * @return false otherwise
 */
static bool is_board_empty(t_game* game)
{
	game->board.empty_cells = 0;
	iter_board(game, count_empty_cells);

	return !(game->board.empty_cells > 0);
}

/**
 * @brief Check if the game is over by checking if there are no valid moves left
 * 
 * @param game	The game structure containing the game state and information for handling input
 * @param i		The row index
 * @param j		The column index
 */
static void can_move(t_game* game, size_t i, size_t j)
{
	if (j + 1 < game->board.size && 
		game->board.cells[i][j] == game->board.cells[i][j + 1])
		game->board.move++;
	
	if (i + 1 < game->board.size && 
		game->board.cells[i][j] == game->board.cells[i + 1][j])
		game->board.move++;
}

/**
 * @brief Check if the game is over
 * 
 * @param game	The game structure containing the game state and information for handling input
 * @return		true If the game is over,
 * @return		false otherwise
 */
static bool game_over(t_game* game)
{
	game->board.move = 0;
	iter_board(game, can_move);

	return game->board.move == 0 && is_board_empty(game);
}

/**
 * @brief Get the random cell object
 * 
 * @param game	The game structure containing the game state and information for handling input
 * @param i		The row index
 * @param j		The column index
 */
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

/**
 * @brief Add a new number (2 or 4) to a random empty cell on the game board
 * 
 * @param game The game structure containing the game state and information for handling input
 */
static void add_number(t_game* game)
{
	game->board.empty_cells = 0;
	iter_board(game, get_random_cell);
	int value = (rand() % 10 == 0) ? 4 : 2;
	game->board.cells[game->board.x][game->board.y] = value;
}

/**
 * @brief Update the maximum tile value on the game board after a move
 * 
 * @param game	The game structure containing the game state and information for handling input
 * @param i		The row index
 * @param j		The column index
 */
static void update_max(t_game* game, size_t i, size_t j)
{
	if (game->board.cells[i][j] > game->board.max)
	{
		game->board.max = game->board.cells[i][j];
	}
}

/**
 * @brief Check if the pressed key is an arrow key
 * 
 * @param key The pressed key
 * @return true If the key is an arrow key,
 * @return false otherwise
 */
static bool is_arrow_key(int key)
{
	return (key == KEY_DOWN || key == KEY_UP || key == KEY_RIGHT || key == KEY_LEFT);
}

/**
 * @brief Update the game state based on the user's input
 * 
 * @param game The game structure containing the game state and information for handling input
 */
void update(t_game* game)
{
	if (!is_arrow_key(game->key))
		return ;

	game->board.moved = false;
	move_cells(game);
	iter_board(game, update_max);

	if (game->board.max >= game->board.win_value && !game->board.has_won)
	{
		game->board.has_won = 1;
		game->state &= ~PLAYING;
		game->state |= WIN;
	}

	if (game->board.moved)
	{
		add_number(game);
	}

	if (game_over(game))
	{
		game->state &= ~PLAYING;
		save_score(game->board.score);
	}
}

/**
 * @brief Start a new game by resetting the game board and adding two random numbers to the board
 * 
 * @param game The game structure containing the game state and information for handling input
 */
void new_game(t_game* game)
{
	game->board.score = 0;
	game->board.max = 0;
	game->state = PLAYING;
	game->board.has_won = 0;
	ft_bzero(game->board.cells, sizeof(game->board.cells));
	add_number(game);
	add_number(game);
}
