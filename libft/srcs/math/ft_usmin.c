/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usmin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:26:15 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Returns the minimum of two unsigned short integers.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return unsigned short The smallest of the two values.
 */
unsigned short	ft_usmin(unsigned short a, unsigned short b)
{
	if (a < b)
		return (a);
	return (b);
}
