/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucclamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:25:42 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:13:08 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Clamps an unsigned char between a minimum and a maximum.
 * 
 * @param n		The value to clamp.
 * @param min	The minimum limit.
 * @param max	The maximum limit.
 * @return unsigned char The clamped value.
 */
unsigned char	ft_ucclamp(
	unsigned char n, unsigned char min, unsigned char max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
