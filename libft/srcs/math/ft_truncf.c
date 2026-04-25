/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:26:02 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:12:40 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"
#include "libft/limits.h"

/**
 * @brief Rounds a float to the nearest integer toward zero.
 * 
 * @param x	The float value to truncate.
 * @return float The truncated value.
 */
float	ft_truncf(float x)
{
	float	res;

	if (x >= 0)
	{
		res = x + FLT_MAX_24 - FLT_MAX_24;
		res -= (res > x);
	}
	else
	{
		res = x - FLT_MAX_24 + FLT_MAX_24;
		res += (res < x);
	}
	return (res);
}
