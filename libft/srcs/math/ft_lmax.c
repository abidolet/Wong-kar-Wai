/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:23:53 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Returns the maximum of two long integers.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return long The largest of the two values.
 */
long	ft_lmax(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}
