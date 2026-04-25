#ifndef FT_2048_H
# define FT_2048_H

/* -------------------------------------------- */
/*                   INCLUDES                   */
/* -------------------------------------------- */

# include "libft.h"

/* -------------------------------------------- */
/*                    TYPEDEF                   */
/* -------------------------------------------- */

typedef enum e_state
{
	MENU = 0,
	LEADERBOARD,
	PLAYING,
	WIN
}	t_state;

typedef struct s_board
{
	size_t		cells[4][4];
	uint16_t	bitboard[65536];
	size_t		size;
	size_t		score;
	size_t		empty_cells;
	size_t		x;
	size_t		y;
	size_t		win_value;
}	t_board;

typedef struct s_game
{
	t_board	board;
	int		key;
	t_state	state;
}	t_game;

enum e_const
{
	WIN_VALUE = 2048,
	KEY_ESCAPE = 27
};

/* -------------------------------------------- */
/*                     FILES                    */
/* -------------------------------------------- */

/* ------------------ draw.c ------------------ */
void	draw(t_game *game);

/* ------------------ update ------------------ */
void	update(t_game *game);
void	new_game(t_game *game);

/* ------------------ move.c ------------------ */
void	move_cells(t_game *game);

/* ------------------- utils ------------------ */
void	iter_board(t_game* game, void (*f)(t_game*, size_t, size_t));

#endif
