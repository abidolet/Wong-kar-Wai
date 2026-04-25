/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:26:08 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 02:52:35 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include <stdlib.h>

t_vector	*ft_vecmerge(t_vector *a, t_vector *b)
{
	t_vector	*res;
	size_t		i;

	if (!a || !b || a->elt_size != b->elt_size)
		return (NULL);
	res = ft_vecnew(a->elt_size, a->del);
	if (!res)
		return (NULL);
	ft_vecreserve(res, a->size + b->size);
	if (!res->data)
	{
		free(res);
		return (NULL);
	}
	i = 0;
	while (i < a->size)
		ft_vecpush_back(res, (char *)a->data + a->elt_size * i++);
	i = 0;
	while (i < b->size)
		ft_vecpush_back(res, (char *)b->data + b->elt_size * i++);
	return (res);
}
