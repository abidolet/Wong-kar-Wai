/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:24:54 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Returns the largest integer value less than or equal to x.
 * 
 * @param x The double value to round down.
 * @return double The floor of x.
 */
double	ft_floor(double x)
{
	const double	t = ft_trunc(x);

	if (x < t)
		return (t - 1.0);
	return (t);
}
