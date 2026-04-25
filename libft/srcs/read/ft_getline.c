/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:33:55 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:51:08 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/read.h"

/**
 * @brief Reads the entire contents of a file into a buffer, stopping at newline.
 * 
 * @param fileptr	A pointer to a buffer where the file contents will be stored.
 * @param n			The size of the buffer pointed to by fileptr.
 * @param fd		The file descriptor to read from.
 * @return ssize_t The number of bytes read, or -1 on error or EOF.
 */
ssize_t	ft_getline(char **lineptr, size_t *n, int fd)
{
	return (ft_getdelim(lineptr, n, '\n', fd));
}
