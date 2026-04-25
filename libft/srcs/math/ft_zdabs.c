/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zdabs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:26:18 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:11 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Computes the absolute value of a ssize_t.
 * 
 * @param n The ssize_t value.
 * @return size_t The absolute value of n.
 */
size_t	ft_zdabs(ssize_t n)
{
	if (n < 0)
		return ((size_t)(-n));
	return ((size_t)n);
}
