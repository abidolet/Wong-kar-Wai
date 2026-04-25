/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:14:20 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:03:49 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"

/**
 * @brief Write formatted output to a string
 * 
 * @param str		Buffer to write to
 * @param format	Format string
 * @return Number of characters printed
 */
int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (result);
}
