/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecreserve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:04:33 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 13:47:25 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"
#include <stdlib.h>

bool	ft_vecreserve(t_vector *vec, size_t new_capacity)
{
	void	*new_data;

	if (!vec)
		return (false);
	if (new_capacity > vec->capacity)
	{
		new_data = malloc(vec->elt_size * new_capacity);
		if (!new_data)
		{
			ft_vecclear(vec);
			return (false);
		}
		if (vec->data)
		{
			ft_memcpy(new_data, vec->data, vec->size * vec->elt_size);
			free(vec->data);
		}
		vec->data = new_data;
		vec->capacity = new_capacity;
	}
	return (true);
}
