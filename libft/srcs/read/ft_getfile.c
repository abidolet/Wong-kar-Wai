/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:44:17 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:49:59 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/read.h"

/**
 * @brief Reads the entire contents of a file into a buffer, stopping at EOF.
 * 
 * @param fileptr	A pointer to a buffer where the file contents will be stored.
 * @param n			The size of the buffer pointed to by fileptr.
 * @param fd		The file descriptor to read from.
 * @return ssize_t The number of bytes read, or -1 on error or EOF.
 */
ssize_t	ft_getfile(char **fileptr, size_t *n, int fd)
{
	return (ft_getdelim(fileptr, n, '\0', fd));
}
