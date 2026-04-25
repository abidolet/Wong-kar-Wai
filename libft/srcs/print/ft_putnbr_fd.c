/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:27:35 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:03:25 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"

/**
 * @brief Output a number to a file descriptor.
 * 
 * @param n		The number to output.
 * @param fd	The file descriptor to write to.
 * @return The number of bytes written.
 */
int	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
		return (ft_putchar_fd('-', fd) + ft_putnbr_fd(-n, fd));
	else if (n < 10)
		return (ft_putchar_fd((char)n + '0', fd));
	return (ft_putnbr_fd(n / 10, fd) + ft_putchar_fd((char)(n % 10) + '0', fd));
}
