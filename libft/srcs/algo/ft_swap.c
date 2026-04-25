/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:15:29 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:03:19 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/algo.h"
#include "libft/mem.h"

/**
 * @brief Swaps the contents of two memory areas of given size.
 * 
 * @param a 
 * @param b 
 * @param size 
 */
void	ft_swap(void *a, void *b, size_t size)
{
	unsigned char	tmp[256];
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			chunk;

	if (!a || !b || size == 0)
		return ;
	p1 = (unsigned char *)a;
	p2 = (unsigned char *)b;
	while (size > 0)
	{
		if (size < sizeof(tmp))
			chunk = size;
		else
			chunk = sizeof(tmp);
		ft_memmove(tmp, p1, chunk);
		ft_memmove(p1, p2, chunk);
		ft_memmove(p2, tmp, chunk);
		p1 += chunk;
		p2 += chunk;
		size -= chunk;
	}
}
