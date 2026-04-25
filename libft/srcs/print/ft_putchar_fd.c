/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:23:27 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:02:49 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"
#include <unistd.h>

/**
 * @brief Output a character to a file descriptor.
 * 
 * @param c		The character to output.
 * @param fd	The file descriptor to write to.
 * @return The number of bytes written.
 */
int	ft_putchar_fd(char c, int fd)
{
	return ((int)write(fd, &c, 1));
}
