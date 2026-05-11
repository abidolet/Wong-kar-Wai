#include "2048.h"
#include <ncurses.h>

/**
 * @brief Handle the user input and update the game state accordingly
 * 
 * @param game The game structure containing the game state and information for handling input
 */
static void back_to_menu(t_game *game)
{
	if (game->key == ENTER || game->key == KEY_ENTER)
	{
		game->state = MENU;
	}
}

/**
 * @brief Handle the user input when the game is in the win state and update the game state accordingly
 * 
 * @param game The game structure containing the game state and information for handling input
 */
static void handle_win(t_game *game)
{
	if (game->key == KEY_UP || game->key == KEY_DOWN)
		game->selected_button = game->selected_button != 0;
	else if (game->key == ENTER || game->key == KEY_ENTER)
	{
		if (game->selected_button == 0)
			game->state = PLAYING;
		else
		{
			save_score(game->board.score);
			game->state = MENU;
			game->board.has_won = 0;
			game->selected_button = 0;
		}
	}
}

/**
 * @brief Handle the user input when the game is in the menu state and update the game state accordingly
 * 
 * @param game The game structure containing the game state and information for handling input
 */
static void handle_menu(t_game *game)
{
	if (game->key == KEY_UP)
		game->selected_button = (game->selected_button - 1 + 4) % 4;
	else if (game->key == KEY_DOWN)
		game->selected_button = (game->selected_button + 1) % 4;
	else if (game->key == ENTER || game->key == KEY_ENTER)
	{
		if (game->selected_button <= 1)
		{
			game->board.size = game->selected_button + 4;
			game->state = LEADERBOARD;
			new_game(game);
		}
		else if (game->selected_button == 2)
			game->state = LEADERBOARD;
		else if (game->selected_button == 3)
			game->key = KEY_ESCAPE;
		game->selected_button = 0;
	}
}

/**
 * @brief Handle the user input and update the game state accordingly
 * 
 * @param game The game structure containing the game state and information for handling input
 */
void handle_input(t_game *game)
{
	if (game->key == KEY_BACKSPACE)
	{
		if (game->state != MENU)
		{
			game->state = MENU;
			game->selected_button = 0;
		}

		return ;
	}

	switch (game->state)
	{
		case MENU:
			handle_menu(game);
			break ;
		case PLAYING:
			update(game);
			break ;
		case WIN:
			handle_win(game);
			break ;
		case LEADERBOARD:
			back_to_menu(game);
			break ;
		default:
			back_to_menu(game);
			break ;
	}
}
