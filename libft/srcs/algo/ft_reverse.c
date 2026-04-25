/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:22:11 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:01:36 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/algo.h"

/**
 * @brief Reverses a portion of an array in place.
 * 
 * @param algo	Struct containing the array information and comparison function.
 * @param begin	Starting index of the portion to reverse.
 * @param end	Ending index of the portion to reverse.
 */
void	ft_reverse(t_algo algo, size_t begin, size_t end)
{
	char	*base;

	if (!algo.base || algo.size == 0 || algo.n <= 1 || begin >= end)
		return ;
	base = (char *)algo.base;
	while (begin < end)
	{
		ft_swap(base + begin * algo.size, base + end * algo.size, algo.size);
		begin++;
		end--;
	}
}
