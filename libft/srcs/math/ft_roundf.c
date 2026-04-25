/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:55:15 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:04:21 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Round to nearest integer, away from zero
 * 
 * @param x The float value to round.
 * @return float The rounded value.
 */
float	ft_roundf(float x)
{
	if (x >= 0)
		return (ft_floorf(x + 0.5f));
	return (ft_ceilf(x - 0.5f));
}
