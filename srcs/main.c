#include "2048.h"
#include <curses.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

static void handle_sigint(int sig)
{
	endwin();
	exit(sig);
}

int main(void)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	srand(time(NULL));
	signal(SIGINT, handle_sigint);

	init_tables(&game.board);
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	new_game(&game);

	while (game.key != KEY_ESCAPE)
	{
		refresh();
		game.key = getch();
		clear();
		draw(&game);
	}
	endwin();
	return (0);
}
