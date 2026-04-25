/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:18:26 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 17:57:05 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/algo.h"

/**
 * @brief Performs a binary search on a sorted array.
 * 
 * @param algo	Struct containing the array information and comparison function.
 * @param key	The value to search for.
 * @return ssize_t The index of the found element, or -1 if not found.
 * @note The array must be sorted according to the comparison function.
 */
ssize_t	ft_binary_search(t_algo algo, const void *key)
{
	size_t	left;
	size_t	right;
	size_t	mid;
	char	*base;

	if (!algo.base || algo.size == 0 || !algo.cmp)
		return (-1);
	base = (char *)algo.base;
	left = 0;
	right = algo.n;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (algo.cmp(base + mid * algo.size, key) == 0)
			return ((ssize_t)mid);
		else if (algo.cmp(base + mid * algo.size, key) < 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
