/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:58:53 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:03:43 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"

/**
 * @brief Write formatted output to a sized buffer
 * 
 * @param str		Buffer to write to
 * @param size		Maximum number of bytes to write
 * @param format	Format string
 * @return Number of characters that would have been printed
 */
int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (result);
}
