/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:24:01 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:01:29 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"
#include "libft/str.h"
#include <unistd.h>

/**
 * @brief Output a string to a file descriptor.
 * 
 * @param s		The string to output.
 * @param fd	The file descriptor to write to.
 * @return The number of bytes written.
 */
int	ft_putstr_fd(char *s, int fd)
{
	return ((int)write(fd, s, ft_strlen(s)));
}
