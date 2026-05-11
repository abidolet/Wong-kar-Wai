#ifndef FT_2048_H
# define FT_2048_H

/* -------------------------------------------- */
/*                   INCLUDES                   */
/* -------------------------------------------- */

# include "libft.h"
# include <stdint.h>

/* -------------------------------------------- */
/*                    TYPEDEF                   */
/* -------------------------------------------- */

# define LEADERBOARD_FILE "/tmp/leaderboard.txt"
# define MAX_LEADERBOARD_ENTRIES 10
# define MAX_SCORE_4 3932104
# define MAX_SCORE_5 3221225476
# define ENTER '\n'

enum e_const
{
	WIN_VALUE = 2048,
	KEY_ESCAPE = 27,
};

typedef enum e_state
{
	MENU = 1 << __COUNTER__,
	LEADERBOARD = 1 << __COUNTER__,
	PLAYING = 1 << __COUNTER__,
	WIN = 1 << __COUNTER__,
}	t_state;

typedef struct s_board
{
	size_t	cells[5][5];
	size_t	size;
	size_t	score;
	size_t	empty_cells;
	size_t	move;
	size_t	x;
	size_t	y;
	size_t	max;
	size_t	win_value;
	bool	moved;
	bool 	has_won;			
}	t_board;

typedef struct s_draw
{
	int	l;
	int	h;
	int	max_x;
	int	max_y;
	int	tot_w;
	int	tot_h;
	int	start_x;
	int	start_y;
}	t_draw;

typedef struct s_game
{
	t_board	board;
	t_draw	draw;
	int		key;
	size_t	selected_button;
	uint8_t	state;
}	t_game;

/* -------------------------------------------- */
/*                   FUNCTIONS                  */
/* -------------------------------------------- */

/* ------------------ draw.c ------------------ */
void		draw(t_game* game);
void		draw_game(t_draw* draw, t_board* board);
void		resize(t_game* game);

/* -------------- draw_screens.c -------------- */
void		draw_menu(t_game* game);
void		draw_end_screen(t_game* game);
void		draw_win_screen(t_game* game);

/* ------------ draw_leaderboard.c ------------ */
void		draw_leaderboard(t_game* game);

/* ----------------- update.c ----------------- */
void		update(t_game *game);
void		new_game(t_game *game);

/* ------------------ move.c ------------------ */
void		move_cells(t_game *game);

/* ------------------ utils.c ----------------- */
void		iter_board(t_game* game, void (*f)(t_game*, size_t, size_t));

/* ------------------ init.c ------------------ */
void		init(t_game* game);

/* --------------- leaderboard.c -------------- */
t_vector*	get_best_scores(void);
void		save_score(uint32_t score);

/* ------------------ input.c ----------------- */
void		handle_input(t_game *game);

#endif
