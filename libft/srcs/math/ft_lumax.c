/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lumax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:24:05 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Returns the maximum of two unsigned long integers.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return unsigned long The largest of the two values.
 */
unsigned long	ft_lumax(unsigned long a, unsigned long b)
{
	if (a > b)
		return (a);
	return (b);
}
