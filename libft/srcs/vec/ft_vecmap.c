/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 01:34:08 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 02:52:09 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include <stdlib.h>

t_vector	*ft_vecmap(t_vector *vec, void *(*f)(void *))
{
	t_vector	*res;
	size_t		i;

	if (!vec || !f || !vec->del)
		return (NULL);
	res = ft_vecnew(vec->elt_size, vec->del);
	if (!res)
		return (NULL);
	ft_vecreserve(res, vec->size);
	if (!res->data)
	{
		free(res);
		return (NULL);
	}
	i = 0;
	while (i < vec->size)
	{
		ft_vecpush_back(res, f((char *)vec->data + i * vec->elt_size));
		i++;
	}
	return (res);
}
