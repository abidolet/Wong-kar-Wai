/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 01:26:31 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/algo.h"

void	ft_vecsort(t_vector *vec, int (*cmp)(const void *, const void *))
{
	if (!vec || !cmp)
		return ;
	ft_qsort((t_algo)
	{
		.base = vec->data,
		.n = vec->size,
		.size = vec->elt_size,
		.cmp = cmp
	});
}
