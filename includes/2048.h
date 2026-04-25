#ifndef FT_2048_H
# define FT_2048_H

# include "libft.h"

typedef enum e_state
{
	MENU = 0,
	LEADERBOARD,
	PLAYING,
	WIN
}	t_state;

typedef struct s_game
{
	size_t	board[5][5];
	size_t	size;
	size_t	score;
	int		key;
	t_state	state;
}	t_game;

enum e_const
{
	WIN_VALUE = 2048,
	KEY_ESCAPE = 27
};

void	draw(t_game *game);
void	update(t_game *game);
void	new_game(t_game *game);

#endif
