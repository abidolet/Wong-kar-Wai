/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdelim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:03:38 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 20:02:42 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/read.h"
#include "libft/mem.h"
#include "libft/math.h"
#include "libft/str.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Reads the entire contents of a file into a buffer, stopping at delim.
 * 
 * @param lineptr       A pointer to a buffer where the read line will be stored.
 * @param n                     The size of the buffer pointed to by lineptr.
 * @param delim         The delimiter character to stop reading at.
 * @param fd            The file descriptor to read from.
 * @return ssize_t The number of bytes read, or -1 on error or EOF.
 * @note If lineptr is NULL or too small, a new buffer will be allocated.
 */
ssize_t	ft_getdelim(char **lineptr, size_t *n, int delim, int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	size_t		pos;
	char		*newline;
	ssize_t		bytes_read;
	size_t		len;

	if (!lineptr || !n || fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (-1);
	pos = 0;
	while (1)
	{
		if (*n <= pos + BUFFER_SIZE + 1)
		{
			*n = ft_zumax(*n * 2, pos + BUFFER_SIZE + 1);
			*lineptr = ft_realloc(*lineptr, *n, pos);
		}
		newline = ft_strchr(buffer[fd], delim);
		if (newline)
		{
			len = (size_t)(newline - buffer[fd] + 1);
			ft_memcpy(*lineptr + pos, buffer[fd], len);
			pos += len;
			(*lineptr)[pos] = '\0';
			ft_memmove(buffer[fd], buffer[fd] + len, ft_strlen(buffer[fd] + len) + 1);
			return ((ssize_t)pos);
		}
		len = ft_strlen(buffer[fd]);
		ft_memcpy(*lineptr + pos, buffer[fd], len);
		pos += len;
		buffer[fd][0] = '\0';
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		else if (bytes_read == 0)
			break ;
		buffer[fd][bytes_read] = '\0';
	}
	(*lineptr)[pos] = '\0';
	return ((ssize_t)pos);
}
