/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 01:30:37 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/algo.h"

ssize_t	ft_vecfind(t_vector *vec, const void *key,
	int (*cmp)(const void *, const void *))
{
	t_algo	algo;

	if (!vec || !key || !cmp)
		return (-1);
	algo = (t_algo)
	{
		.base = vec->data,
		.n = vec->size,
		.size = vec->elt_size,
		.cmp = cmp
	};
	return (ft_linear_search(algo, key));
}
