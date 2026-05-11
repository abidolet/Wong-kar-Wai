#include "2048.h"
#include <curses.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

int g_signal = 0;

static void handle_signal(int sig)
{
	g_signal = sig;
}

int main(void)
{
	t_game game = {0};

	srand(time(NULL));
	signal(SIGINT, handle_signal);
	signal(SIGWINCH, handle_signal);
	init(&game);

	while (game.key != KEY_ESCAPE)
	{
		game.key = getch();

		if (g_signal == SIGWINCH || game.key == KEY_RESIZE)
		{
			resize(&game);
			g_signal = 0;
		}
		else if (g_signal != 0)
		{
			break ;
		}
		else
		{
			handle_input(&game);
			clear();
			draw(&game);
			refresh();
		}
	}

	endwin();
	return (0);
}
