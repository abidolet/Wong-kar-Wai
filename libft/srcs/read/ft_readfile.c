/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:01:22 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 19:56:18 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/read.h"
#include "libft/print.h"
#include <stdlib.h>
#include "libft/str.h"
#include "libft/vec.h"
#include "libft/mem.h"

/**
 * @brief Free a line stored in the vector.
 * 
 * @param line The line to free.
 */
static void	free_line(void *line)
{
	free(*(char **)line);
}

/**
 * @brief Read the file and store each line in a vector.
 * 
 * @param res	Vector to store the lines.
 * @param fd	File descriptor to read from.
 * @param line	Buffer to store the current line.
 */
static void	read_file_into_vector(t_vector *res, int fd, char **line)
{
	char		*tmp;
	size_t		n;
	ssize_t		ret;

	n = 0;
	ret = -1;
	while (ret != 0)
	{
		ret = ft_getline(line, &n, fd);
		if (ret < 0)
		{
			ft_vecclear(res);
			free(res);
			return ;
		}
		tmp = ft_strdup(*line);
		if (!tmp || !ft_vecpush_back(res, &tmp))
		{
			free(tmp);
			ft_vecclear(res);
			free(res);
			return ;
		}
		ft_bzero(*line, n);
	}
}

/**
 * @brief Read the file from the given file descriptor and return each lines.
 * 
 * @param fd The file descriptor to read from.
 * @return t_vector* A vector of lines, NULL if an error occurred.
 */
t_vector	*ft_readfile(int fd)
{
	t_vector	*res;
	char		*line;

	res = ft_vecnew(sizeof(char *), free_line);
	if (!res)
		return (NULL);
	line = NULL;
	read_file_into_vector(res, fd, &line);
	free(line);
	return (res);
}
