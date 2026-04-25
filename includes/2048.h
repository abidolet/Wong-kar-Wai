#ifndef FT_2048_H
# define FT_2048_H

# include "libft.h"

typedef enum e_state
{
	MENU = 0,
	LEADERBOARD,
	PLAYING,
}	t_state;

typedef struct s_game
{
	size_t	board[5][5];
	size_t	size;
	size_t	score;
	int		key;
	t_state	state;
}	t_game;

# define KEY_ESCAPE 27

void	draw(t_game *game);
void	update(t_game *game);

#endif
