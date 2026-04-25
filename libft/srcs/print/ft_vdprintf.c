/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:16:28 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:04:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Write formatted output to a file descriptor using a va_list
 * 
 * @param fd	File descriptor to write to
 * @param str	Format string
 * @param ap	Variadic argument list
 * @return Number of characters printed, or -1 on error
 */
int	ft_vdprintf(int fd, const char *str, va_list ap)
{
	int		size;
	char	*strp;

	size = ft_vasprintf(&strp, str, ap);
	if (size != -1)
	{
		size = (int)write(fd, strp, (size_t)size);
		free(strp);
	}
	return (size);
}
