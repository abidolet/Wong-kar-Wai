/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zdclamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:26:22 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:14:13 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Clamps a ssize_t value between a minimum and a maximum.
 * 
 * @param n		The value to clamp.
 * @param min	The minimum limit.
 * @param max	The maximum limit.
 * @return ssize_t The clamped value.
 */
ssize_t	ft_zdclamp(ssize_t n, ssize_t min, ssize_t max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
