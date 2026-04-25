/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:25:28 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:05:59 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Smallest integral value not less than argument of a double
 * 
 * @param x The double value to round up.
 * @return double The ceiling of x.
 */
double	ft_ceil(double x)
{
	const double	t = ft_trunc(x);

	if (x > t)
		return (t + 1.0);
	return (t);
}
