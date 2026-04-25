/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luclamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:24:01 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Clamps an unsigned long integer between a minimum and a maximum.
 * 
 * @param n The value to clamp.
 * @param min The minimum limit.
 * @param max The maximum limit.
 * @return unsigned long The clamped value.
 */
unsigned long	ft_luclamp(
	unsigned long n, unsigned long min, unsigned long max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
