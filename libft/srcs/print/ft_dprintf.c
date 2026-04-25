/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:11:19 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:01:42 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"

/**
 * @brief Write formatted output to a file descriptor
 * 
 * @param fd		File descriptor to write to
 * @param format	Format string
 * @return Number of characters printed, or -1 on error
 */
int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (result);
}
