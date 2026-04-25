/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:22:53 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"

/**
 * @brief Returns the minimum of two char values.
 * 
 * @param a The first value.
 * @param b The second value.
 * @return char The smallest of the two values.
 */
char	ft_cmin(char a, char b)
{
	if (a < b)
		return (a);
	return (b);
}
