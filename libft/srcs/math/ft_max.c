/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:00:00 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 20:00:00 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Returns the maximum of two integers.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return int The largest of the two values.
 */
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
