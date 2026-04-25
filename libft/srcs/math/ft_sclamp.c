/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:25:32 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:12:21 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Clamps a short integer between a minimum and a maximum.
 * 
 * @param n		The value to clamp.
 * @param min	The minimum limit.
 * @param max	The maximum limit.
 * @return short The clamped value.
 */
short	ft_sclamp(short n, short min, short max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
