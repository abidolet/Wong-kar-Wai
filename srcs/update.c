#include "2048.h"
#include <ncurses.h>
#include <stdlib.h>

static bool is_game_over(t_board* board)
{
	uint64_t bitboard = board->bitboard;
	uint64_t transposed = transpose(bitboard);
	uint64_t left = get_board(bitboard, board->lut_left);
	uint64_t right = get_board(bitboard, board->lut_right);
	uint64_t up = get_board(transposed, board->lut_left);
	uint64_t down = get_board(transposed, board->lut_right);

	return left == bitboard && right == bitboard && up == transposed
		   && down == transposed;
}

/**
 * @brief Get the empty cells object
 *
 * @param board The game board
 * @param empty_cells An array to store the indices of empty cells
 * @return int The number of empty cells
 */
int get_empty_cells(uint64_t board, size_t* empty_cells)
{
	size_t count = 0;

	for (size_t i = 0; i < 16; i++)
	{
		if (((board >> (i * 4)) & 0xF) == 0)
		{
			empty_cells[count++] = i;
		}
	}

	return count;
}

/**
 * @brief Adds a new number to the game board
 *
 * @param board The game board
 */
static void add_number(uint64_t* board)
{
	size_t empty_cells[16];
	size_t count;
	size_t random_idx;
	uint64_t tile;

	count = get_empty_cells(*board, empty_cells);
	random_idx = empty_cells[rand() % count];
	tile = (rand() % 10 == 0) ? 2 : 1;

	*board = *board | (tile << ((u_int64_t)random_idx * 4));
}

static size_t get_max_value(uint64_t bitboard)
{
	uint64_t max_exp = 0;

	for (int i = 0; i < 16; i++)
	{
		uint64_t exp = (bitboard >> (i * 4)) & 0xF;
		if (exp > max_exp)
			max_exp = exp;
	}
	return (size_t)1 << max_exp;
}

/**
 * @brief Updates the game state
 *
 * @param game The game instance
 */
void update(t_game* game)
{
	uint64_t new_board = move_cells(game);

	if (new_board != game->board.bitboard)
	{
		game->board.bitboard = new_board;
		add_number(&game->board.bitboard);
	}

	if (get_max_value(game->board.bitboard) >= game->board.win_value
		&& !(game->state & WIN))
	{
		game->state &= ~PLAYING;
		game->state |= WIN;
	}

	if (is_game_over(&game->board))
	{
		ft_dprintf(2, "Game Over\n");
		game->state &= ~PLAYING;
	}

	iter_board(game, bitboard_to_grid);
}

/**
 * @brief Starts a new game
 *
 * @param game The game instance
 */
void new_game(t_game* game)
{
	game->board.bitboard = 0;
	game->board.score = 0;
	game->board.size = 4;
	game->state = PLAYING;

	add_number(&game->board.bitboard);
	add_number(&game->board.bitboard);
	iter_board(game, bitboard_to_grid);
}
