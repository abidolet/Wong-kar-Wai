#include "2048.h"
#include <curses.h>
#include <stdlib.h>

/**
 * @brief Draws the frame of the leaderboard
 * 
 * @param start_x	Defines the x coordinate of the top left corner of the frame
 * @param start_y 	Defines the y coordinate of the top left corner of the frame
 * @param width		Defines the width of the frame
 */
static void	draw_leaderboard_frame(int start_x, int start_y, int width)
{
	int	height = 15;

	mvaddch(start_y, start_x, ACS_ULCORNER);
	for (int i = 1; i < width - 1; i++)
		mvaddch(start_y, start_x + i, ACS_HLINE);
	mvaddch(start_y, start_x + width - 1, ACS_URCORNER);

	attron(COLOR_PAIR(11) | A_BOLD);
	mvprintw(start_y + 1, start_x + (width / 2) - 6, " TOP SCORES ");
	attroff(COLOR_PAIR(11) | A_BOLD);

	for (int i = 1; i < height; i++)
	{
		mvaddch(start_y + i, start_x, ACS_VLINE);
		mvaddch(start_y + i, start_x + width - 1, ACS_VLINE);
	}

	mvaddch(start_y + height, start_x, ACS_LLCORNER);
	for (int i = 1; i < width - 1; i++)
		mvaddch(start_y + height, start_x + i, ACS_HLINE);
	mvaddch(start_y + height, start_x + width - 1, ACS_LRCORNER);
}

/**
 * @brief Comparison function for sorting the scores in descending order
 * 
 * @param a First score to compare
 * @param b	Second score to compare
 * @return int The difference between the two scores
 */
int cmp(const void *a, const void *b)
{
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;

    if (!s1 || !s2) return 0;

    int n1 = ft_atoi(s1);
    int n2 = ft_atoi(s2);

    return (n2 - n1); 
}

/**
 * @brief Draws the list of scores on the leaderboard
 * 
 * @param start_x	Defines the x coordinate of the top left corner of the frame
 * @param start_y	Defines the y coordinate of the top left corner of the frame
 */
static void	draw_scores_list(int start_x, int start_y)
{
	t_vector	*best_scores = get_best_scores();
	size_t		size;
	char		**score_str;

	if (!best_scores || ft_vecsize(best_scores) == 0)
	{
		mvprintw(start_y + 5, start_x + 8, "No scores found");
		return ;
	}

	ft_vecsort(best_scores, cmp);

	size = MIN(ft_vecsize(best_scores) - 1, MAX_LEADERBOARD_ENTRIES);
	for (size_t i = 0; i < size; i++)
	{
		score_str = (char **)ft_vecat(best_scores, i);
		if (score_str && *score_str)
		{
			int score = (unsigned int)ft_atoi(*score_str);
			mvprintw(start_y + 3 + i, start_x + 4, "%2zu.", i + 1);
			mvprintw(start_y + 3 + i, start_x + 12, "%10u", score);
		}
	}

	ft_vecclear(best_scores);
	free(best_scores);
}

/**
 * @brief Draws the leaderboard
 * 
 * @param game The game structure containing the draw information and the selected button index
 */
void	draw_leaderboard(t_game *game)
{
	int	width = 30;
	int	start_x = (game->draw.max_x / 2) - (width / 2);
	int	start_y = (game->draw.max_y / 2) - 8;

	draw_leaderboard_frame(start_x, start_y, width);

	draw_scores_list(start_x, start_y);

	if (game->selected_button == 0)
		attron(A_REVERSE);
	mvprintw(start_y + 17, (game->draw.max_x / 2) - 8, "[ Back to Menu ]");
	if (game->selected_button == 0)
		attroff(A_REVERSE);
}
