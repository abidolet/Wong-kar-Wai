/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:22:34 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:11 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Computes the absolute value of a signed char.
 * 
 * @param n The signed char value.
 * @return unsigned char The absolute value of n.
 */
unsigned char	ft_cabs(char n)
{
	if (n < 0)
		return ((unsigned char)-n);
	return ((unsigned char)n);
}
