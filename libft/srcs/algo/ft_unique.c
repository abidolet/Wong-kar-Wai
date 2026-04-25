/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:44:50 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:30:38 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/algo.h"
#include "libft/mem.h"

/**
 * @brief Removes duplicates from a sorted array in place.
 * 
 * @param algo The algorithm structure containing the array and its properties.
 * @return ssize_t The new length of the array or -1 on error.
 */
ssize_t	ft_unique(t_algo algo)
{
	size_t	i;
	size_t	k;
	char	*base;

	if (!algo.base || algo.size == 0 || !algo.cmp)
		return (-1);
	if (algo.n <= 1)
		return ((ssize_t)algo.n);
	i = 1;
	k = 0;
	base = (char *)algo.base;
	while (i < algo.n)
	{
		if (algo.cmp(base + i * algo.size, base + k * algo.size) != 0)
		{
			k++;
			if (i != k)
				ft_memcpy(base + k * algo.size, base + i * algo.size,
					algo.size);
		}
		i++;
	}
	return ((ssize_t)(k + 1));
}
