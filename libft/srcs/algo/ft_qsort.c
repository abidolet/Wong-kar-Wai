/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:14:14 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:04:17 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/algo.h"

/**
 * @brief Partitions the array using Hoare's scheme.
 * @internal
 * @param algo	Struct containing the array information and comparison function.
 * @param i 	Pointer to the index for the left partition.
 * @param j		Pointer to the index for the right partition.
 * @param base	Pointer to the base of the array.
 */
static void	partition(
	t_algo algo, size_t *i, size_t *j, char **base)
{
	char	*pivot;

	*base = (char *)algo.base;
	pivot = *base + (algo.n / 2) * algo.size;
	*i = 0;
	*j = algo.n - 1;
	while (*i <= *j)
	{
		while (algo.cmp(base + *i * algo.size, pivot) < 0)
			(*i)++;
		while (algo.cmp(base + *j * algo.size, pivot) > 0)
			(*j)--;
		if (*i <= *j)
		{
			ft_swap(base + algo.size * *i, base + algo.size * *j,
				algo.size);
			(*i)++;
			(*j)--;
		}
	}
}

/**
 * @brief Sorts an array using the quicksort algorithm.
 * 
 * @param algo	Struct containing the array information and comparison function.
 */
void	ft_qsort(t_algo algo)
{
	char	*base_ptr;
	size_t	i;
	size_t	j;

	if (!algo.base || algo.size == 0 || algo.n <= 1 || !algo.cmp)
		return ;
	partition(algo, &i, &j, &base_ptr);
	if (j > 0)
	{
		algo.base = base_ptr;
		algo.n = j + 1;
		ft_qsort(algo);
	}
	if (i < algo.n)
	{
		algo.base = base_ptr + i * algo.size;
		algo.n = algo.n - i;
		ft_qsort(algo);
	}
}
