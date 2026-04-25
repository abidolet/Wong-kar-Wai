/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceilf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:25:28 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:06:02 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Smallest integral value not less than argument of a float
 * 
 * @param x The float value to round up.
 * @return float The ceiling of x.
 */
float	ft_ceilf(float x)
{
	const float	t = ft_truncf(x);

	if (x > t)
		return (t + 1.0f);
	return (t);
}
