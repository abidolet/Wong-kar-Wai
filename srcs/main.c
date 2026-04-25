#include "2048.h"
#include <curses.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int sig)
{
	endwin();
	exit(sig);
}

int main(void)
{
	t_game game;

	signal(SIGINT, handle_sigint);
	ft_bzero(&game, sizeof(t_game));
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	while (game.key != KEY_ESCAPE)
	{
		refresh();
		game.key = getch();
		INFO("Key pressed: %d", game.key);
		draw(&game);
	}
	endwin();
	return (0);
}
