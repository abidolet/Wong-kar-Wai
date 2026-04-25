/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:03:17 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"

bool	ft_vecinsert(t_vector *vec, size_t index, void *element)
{
	const char	*data;
	void		*dest;
	void		*src;
	size_t		n;

	if (!vec || index > vec->size || !element)
		return (false);
	if (vec->size >= vec->capacity)
	{
		if (vec->capacity == 0)
			n = 1;
		else
			n = vec->capacity * 2;
		if (!ft_vecreserve(vec, n))
			return (false);
	}
	data = (const char *)vec->data;
	dest = (void *)(data + (index + 1) * vec->elt_size);
	src = (void *)(data + index * vec->elt_size);
	n = (vec->size - index) * vec->elt_size;
	ft_memmove(dest, src, n);
	dest = (void *)(data + index * vec->elt_size);
	ft_memcpy(dest, element, vec->elt_size);
	vec->size++;
	return (true);
}
