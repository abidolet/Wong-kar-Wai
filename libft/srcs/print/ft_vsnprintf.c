/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:59:41 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:05:05 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/mem.h"

/**
 * @brief Write formatted output to a sized buffer using a va_list
 * 
 * @param str		Buffer to write to
 * @param size		Maximum number of bytes to write
 * @param format	Format string
 * @param ap		Variadic argument list
 * @return Number of characters that would have been printed
 */
int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_data	data;

	if (!str || !format)
		return (-1);
	ft_bzero(&data, sizeof(t_data));
	data.str = str;
	data.fmt = (char *)format;
	data.size = size;
	va_copy(data.arg, ap);
	run(&data);
	va_end(data.arg);
	str[data.n] = 0;
	return ((int)data.n);
}
