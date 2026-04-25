/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:26:02 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:12:37 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"
#include "libft/limits.h"

/**
 * @brief Rounds a double to the nearest integer toward zero.
 * 
 * @param x The double value to truncate.
 * @return double The truncated value.
 */
double	ft_trunc(double x)
{
	double	res;

	if (x >= 0)
	{
		res = x + DBL_MAX_53 - DBL_MAX_53;
		res -= (res > x);
	}
	else
	{
		res = x - DBL_MAX_53 + DBL_MAX_53;
		res += (res < x);
	}
	return (res);
}
