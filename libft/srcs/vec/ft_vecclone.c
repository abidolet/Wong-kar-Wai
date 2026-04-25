/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:20:47 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 02:49:44 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"

t_vector	*ft_vecclone(t_vector *vec)
{
	t_vector	*clone;

	if (!vec)
		return (NULL);
	clone = ft_vecnew(vec->elt_size, vec->del);
	if (!clone)
		return (NULL);
	ft_vecreserve(clone, vec->capacity);
	if (!clone->data && vec->capacity > 0)
	{
		free(clone);
		return (NULL);
	}
	if (vec->size > 0)
		ft_memcpy(clone->data, vec->data, vec->size * vec->elt_size);
	clone->size = vec->size;
	return (clone);
}
