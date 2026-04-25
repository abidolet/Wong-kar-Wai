/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:01:01 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:05:27 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"

/**
 * @brief Write formatted output to a string using a va_list
 * 
 * @param str		Buffer to write to
 * @param format	Format string
 * @param ap		Variadic argument list
 * @return Number of characters printed
 */
int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, (size_t)-1, format, ap));
}
