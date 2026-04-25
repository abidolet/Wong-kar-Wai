/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cclamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:22:40 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:06:40 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Clamps a char value between a minimum and a maximum.
 * 
 * @param n		The value to clamp.
 * @param min	The minimum limit.
 * @param max	The maximum limit.
 * @return char The clamped value.
 */
char	ft_cclamp(char n, char min, char max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
