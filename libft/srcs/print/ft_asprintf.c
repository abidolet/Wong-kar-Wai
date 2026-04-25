/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:02:21 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:00:28 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write formatted output to a dynamically allocated string
 * 
 * @param strp	Pointer to string where output will be stored
 * @param fmt	Format string
 * @return Number of characters printed, or -1 on error
 */
int	ft_asprintf(char **strp, const char *fmt, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, fmt);
	result = ft_vasprintf(strp, fmt, ap);
	va_end(ap);
	return (result);
}
