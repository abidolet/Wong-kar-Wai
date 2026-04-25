/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uclamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:25:48 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:13:22 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Clamps an unsigned integer between a minimum and a maximum.
 * 
 * @param n		The value to clamp.
 * @param min	The minimum limit.
 * @param max	The maximum limit.
 * @return unsigned int The clamped value.
 */
unsigned int	ft_uclamp(unsigned int n, unsigned int min, unsigned int max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
