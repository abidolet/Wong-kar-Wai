/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:51:31 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/26 17:51:33 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/algo.h"
#include "libft/mem.h"
#include <stdlib.h>

/**
 * @brief Partitions the array for quicksort. Chooses a pivot and rearranges elements.
 * 
 * @param algo The sorting algorithm context containing the array and comparison function.
 * @param i Pointer to the index that will mark the end of the left partition.
 * @param j Pointer to the index that will mark the start of the right partition.
 */
static void partition(t_algo algo, size_t *i, size_t *j)
{
    char    *base;
    size_t  pivot_val;

    base = (char *)algo.base;
    
    // On copie la valeur (le pointeur vers la string) directement
    // On part du principe que algo.size <= sizeof(size_t)
    ft_memcpy(&pivot_val, base + (algo.n / 2) * algo.size, algo.size);

    *i = 0;
    *j = algo.n - 1;
    while (*i <= *j)
    {
        while (algo.cmp(base + (*i * algo.size), &pivot_val) < 0)
            (*i)++;
        while (algo.cmp(base + (*j * algo.size), &pivot_val) > 0)
            (*j)--;
        
        if (*i <= *j)
        {
            ft_swap(base + (*i * algo.size), base + (*j * algo.size), algo.size);
            (*i)++;
            if (*j > 0)
                (*j)--;
        }
    }
}

/**
 * @brief Sorts an array using the quicksort algorithm.
 */
void ft_qsort(t_algo algo)
{
	size_t i;
	size_t j;

	if (!algo.base || algo.size == 0 || algo.n <= 1 || !algo.cmp)
		return ;
	partition(algo, &i, &j);
	if (j > 0)
	{
		t_algo left = algo;
		left.n = j + 1;
		ft_qsort(left);
	}
	if (i < algo.n)
	{
		t_algo right = algo;
		right.base = (char*)algo.base + i * algo.size;
		right.n = algo.n - i;
		ft_qsort(right);
	}
}
