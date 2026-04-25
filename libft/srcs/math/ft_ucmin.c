/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucmin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:25:55 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Returns the minimum of two unsigned char values.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return unsigned char The smallest of the two values.
 */
unsigned char	ft_ucmin(unsigned char a, unsigned char b)
{
	if (a < b)
		return (a);
	return (b);
}
