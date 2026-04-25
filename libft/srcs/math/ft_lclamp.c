/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lclamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:23:49 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Clamps a long integer between a minimum and a maximum.
 * 
 * @param n The value to clamp.
 * @param min The minimum limit.
 * @param max The maximum limit.
 * @return long The clamped value.
 */
long	ft_lclamp(long n, long min, long max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
