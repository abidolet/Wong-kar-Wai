#include "2048.h"
#include <curses.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

int g_signal = 0;

static void handle_signal(int sig)
{
	if (sig == SIGWINCH)
	{
		g_signal = 1;
		return;
	}

	endwin();
	exit(sig);
}

static bool is_arrow_key(int key)
{
	return (key == KEY_DOWN || key == KEY_UP || key == KEY_RIGHT || key == KEY_LEFT);
}

static bool is_key_valid(int key)
{
	return (is_arrow_key(key) || key == KEY_ENTER || key == '\n'
			|| key == '\r');
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

		if (g_signal == 1 || game.key == KEY_RESIZE)
		{
			resize(&game);
			g_signal = 0;
		}
		else if (is_key_valid(game.key))
		{
			if (is_arrow_key(game.key) && (game.state & PLAYING))
			{
				update(&game);
			}

			draw(&game);
		}
	}

	endwin();
	return (0);
}
