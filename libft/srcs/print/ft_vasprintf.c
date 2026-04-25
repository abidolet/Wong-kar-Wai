/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:02:30 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:04:33 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/mem.h"
#include <stdlib.h>

/**
 * @brief Write formatted output to a dynamically allocated string
 * 
 * @param strp	Pointer to string where output will be stored
 * @param fmt	Format string
 * @param ap	Variadic argument list
 * @return Number of characters printed, or -1 on error
 */
int	ft_vasprintf(char **strp, const char *fmt, va_list ap)
{
	t_data	data;

	if (!strp || !fmt)
		return (-1);
	ft_bzero(&data, sizeof(t_data));
	data.fmt = (char *)fmt;
	data.size = (size_t)-1;
	va_copy(data.arg, ap);
	run(&data);
	va_end(data.arg);
	*strp = malloc(data.n + 1);
	return (ft_vsnprintf(*strp, data.n + 1, fmt, ap));
}
