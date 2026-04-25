/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:22:49 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Returns the maximum of two char values.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return char The largest of the two values.
 */
char	ft_cmax(char a, char b)
{
	if (a > b)
		return (a);
	return (b);
}
