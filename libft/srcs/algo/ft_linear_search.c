/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:20:47 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 17:57:46 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/algo.h"

/**
 * @brief Performs a linear search on an array.
 * 
 * @param algo	Struct containing the array information and comparison function.
 * @param key	The value to search for.
 * @return ssize_t The index of the found element, or -1 if not found.
 */
ssize_t	ft_linear_search(t_algo algo, const void *key)
{
	size_t	i;
	char	*base;

	if (!algo.base || algo.size == 0 || !algo.cmp)
		return (-1);
	i = 0;
	base = (char *)algo.base;
	while (i < algo.n)
	{
		if (algo.cmp(base + i * algo.size, key) == 0)
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}
