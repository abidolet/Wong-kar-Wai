/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:05:06 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 13:54:07 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/mem.h"

bool	ft_vecresize(t_vector *vec, size_t new_size)
{
	size_t	i;

	if (!vec)
		return (false);
	if (new_size > vec->size)
	{
		if (new_size > vec->capacity)
			if (!ft_vecreserve(vec, new_size))
				return (false);
		ft_bzero((char *)vec->data + (vec->size * vec->elt_size),
			(new_size - vec->size) * vec->elt_size);
	}
	else if (new_size < vec->size && vec->del)
	{
		i = new_size;
		while (i < vec->size)
		{
			vec->del((char *)vec->data + (i * vec->elt_size));
			i++;
		}
	}
	vec->size = new_size;
	return (true);
}
