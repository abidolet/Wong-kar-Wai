#include "2048.h"
#include <ncurses.h>

/**
 * @brief Get the score object
 * 
 * @param board The game board
 * @param lut_score The lookup table for scores
 * @return uint32_t The total score for the given board
 */
uint32_t get_score(uint64_t board, uint32_t* lut_score)
{
	uint32_t score = 0;

	score += lut_score[(board >> 0) & 0xFFFF];
	score += lut_score[(board >> 16) & 0xFFFF];
	score += lut_score[(board >> 32) & 0xFFFF];
	score += lut_score[(board >> 48) & 0xFFFF];

	return score;
}

/**
 * @brief Transposes the bits of a 64-bit value
 * 
 * @param x The value to transpose
 * @return uint64_t The transposed value
 */
uint64_t transpose(uint64_t x)
{
	uint64_t t;

	t = (x ^ (x >> 12)) & 0x0000F0F00000F0F0ULL;
	x = x ^ t ^ (t << 12);
	t = (x ^ (x >> 24)) & 0x00000000FF00FF00ULL;
	x = x ^ t ^ (t << 24);

	return x;
}

/**
 * @brief Get the board object
 * 
 * @param board The game board
 * @param lut The lookup table for board values
 * @return uint64_t The transposed board after applying the lookup table
 */
uint64_t get_board(uint64_t board, uint16_t* lut)
{
	uint64_t res = 0;

	res |= (uint64_t)lut[(board >> 0) & 0xFFFF] << 0;
	res |= (uint64_t)lut[(board >> 16) & 0xFFFF] << 16;
	res |= (uint64_t)lut[(board >> 32) & 0xFFFF] << 32;
	res |= (uint64_t)lut[(board >> 48) & 0xFFFF] << 48;

	return res;
}

/**
 * @brief Moves the cells on the game board
 * 
 * @param game The game instance
 * @return uint64_t The updated board state
 */
uint64_t move_cells(t_game* game)
{
	bool is_vertical = (game->key == KEY_UP || game->key == KEY_DOWN);
	uint64_t res = game->board.bitboard;
	bool is_left = (game->key == KEY_LEFT || game->key == KEY_UP);
	uint16_t* lut = is_left ? game->board.lut_left : game->board.lut_right;

	if (is_vertical)
	{
		res = transpose(game->board.bitboard);
	}

	res = get_board(res, lut);

	if (is_vertical)
	{
		res = transpose(res);
	}

	if (res != game->board.bitboard)
	{
		game->board.score += get_score(res, game->board.lut_score);
	}

	return res;
}
