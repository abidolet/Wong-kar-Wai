/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usclamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:26:08 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:14:03 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Clamps an unsigned short integer between a minimum and a maximum.
 * 
 * @param n		The value to clamp.
 * @param min	The minimum limit.
 * @param max	The maximum limit.
 * @return unsigned short The clamped value.
 */
unsigned short	ft_usclamp(
	unsigned short n, unsigned short min, unsigned short max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
