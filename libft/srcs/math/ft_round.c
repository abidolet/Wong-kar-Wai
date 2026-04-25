/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:55:15 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:04:38 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief round to nearest integer, away from zero
 * 
 * @param x The double value to round.
 * @return double The rounded value.
 */
double	ft_round(double x)
{
	if (x >= 0)
		return (ft_floor(x + 0.5));
	return (ft_ceil(x - 0.5));
}
