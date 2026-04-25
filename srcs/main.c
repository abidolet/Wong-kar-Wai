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

static bool is_key_valid(int key)
{
	return (key >= KEY_DOWN && key <= KEY_LEFT);
}

int main(void)
{
	t_game game = {0};

	srand(time(NULL));
	signal(SIGINT, handle_signal);
	signal(SIGWINCH, handle_signal);
	init_curses();
	init_game(&game);

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
		else if (is_key_valid(game.key) && game.state == PLAYING)
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
