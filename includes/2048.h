#ifndef FT_2048_H
#define FT_2048_H

/* -------------------------------------------- */
/*                   INCLUDES                   */
/* -------------------------------------------- */

#include "libft.h"
#include <stdint.h>

/* -------------------------------------------- */
/*                    TYPEDEF                   */
/* -------------------------------------------- */

enum e_const
{
	WIN_VALUE = 2048,
	KEY_ESCAPE = 27
};

typedef enum e_state
{
	MENU = 0,
	LEADERBOARD,
	PLAYING,
	WIN
} t_state;

typedef struct s_board
{
	size_t cells[4][4];
	size_t size;
	uint32_t score;
	uint64_t bitboard;
	uint16_t lut_left[UINT16_MAX + 1];
	uint16_t lut_right[UINT16_MAX + 1];
	uint32_t lut_score[UINT16_MAX + 1];
	size_t win_value;
} t_board;

typedef struct s_game
{
	t_board board;
	int key;
	t_state state;
} t_game;

/* -------------------------------------------- */
/*                     FILES                    */
/* -------------------------------------------- */

/* ------------------ draw.c ------------------ */
void draw(t_game* game);

/* ------------------ update ------------------ */
void update(t_game* game);
void new_game(t_game* game);

/* ------------------ move.c ------------------ */
uint64_t move_cells(t_game* game);

/* ------------------- utils ------------------ */
void iter_board(t_game* game, void (*f)(t_game*, size_t, size_t));
void bitboard_to_grid(t_game* game, size_t i, size_t j);
void grid_to_bitboard(t_game* game, size_t i, size_t j);

/* ------------------- init ------------------- */
void init_tables(t_board* board);

#endif
