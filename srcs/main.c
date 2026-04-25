#include "2048.h"
#include <curses.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

int g_signal = 0;

static void handle_sigint(int sig)
{
	endwin();
	exit(sig);
}

static void handle_sigwinch(int sig)
{
	(void)sig;
	g_signal = 1;
}

int main(void)
{
	t_game game;

	srand(time(NULL));
	signal(SIGINT, handle_sigint);
	signal(SIGWINCH, handle_sigwinch);
	ft_bzero(&game, sizeof(t_game));
	initscr();
	curs_set(0);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();

	clear();
	draw(&game);
	refresh();

	while (game.key != KEY_ESCAPE)
	{
		game.key = getch();

		if (g_signal == 1 || game.key == KEY_RESIZE)
		{
			endwin(); 
			refresh();
			clear();
			draw(&game);
			refresh();
			g_signal = 0;
		}
		else if (game.state == PLAYING && 
                (game.key == KEY_UP || game.key == KEY_DOWN || 
                 game.key == KEY_LEFT || game.key == KEY_RIGHT))
		{
			update(&game);
			clear();
			draw(&game);
			refresh();
		}
	}
	endwin();
	return (0);
}
