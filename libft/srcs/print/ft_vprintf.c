/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:15:44 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:04:56 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"

/**
 * @brief Write formatted output to stdout using a va_list
 * 
 * @param str	Format string
 * @param ap	Variadic argument list
 * @return Number of characters printed, or -1 on error
 */
int	ft_vprintf(const char *str, va_list ap)
{
	return (ft_vdprintf(1, str, ap));
}
