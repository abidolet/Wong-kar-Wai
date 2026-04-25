/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:22:39 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:02:56 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/algo.h"

/**
 * @brief Rotates an array in place by k positions in the specified side.
 * 
 * @param algo 	Struct containing the array information and comparison function.
 * @param k 	Number of positions to rotate the array.
 * @param side 	Side of the rotation (1 for right, -1 for left).
 */
void	ft_rotate(t_algo algo, size_t k, int side)
{
	if (!algo.base || algo.size == 0 || algo.n <= 1 || side == 0)
		return ;
	k %= algo.n;
	if (k == 0)
		return ;
	if (side < 0)
		k = algo.n - k;
	ft_reverse(algo, 0, algo.n - 1);
	ft_reverse(algo, 0, k - 1);
	ft_reverse(algo, k, algo.n - 1);
}
