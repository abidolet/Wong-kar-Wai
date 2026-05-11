#include "2048.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Save the score to the leaderboard file
 * 
 * @param score The score to save
 */
void save_score(uint32_t score)
{
	int fd = open(LEADERBOARD_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		return;
	}

	ft_dprintf(fd, "%u\n", score);
	close(fd);
}

/**
 * @brief Get the best scores object
 * 
 * @return t_vector* A vector containing the best scores read from the leaderboard file,
 * @return NULL if the file cannot be read
 */
t_vector* get_best_scores(void)
{
	int fd = open(LEADERBOARD_FILE, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}

	t_vector* best_scores = ft_readfile(fd);
	close(fd);
	return (best_scores);
}
