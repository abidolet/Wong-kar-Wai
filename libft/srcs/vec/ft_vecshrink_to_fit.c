/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecshrink_to_fit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:05:42 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 13:47:57 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"
#include <stdlib.h>

bool	ft_vecshrink_to_fit(t_vector *vec)
{
	void	*new_data;

	if (!vec)
		return (false);
	if (vec->capacity > vec->size)
	{
		if (vec->size == 0)
			new_data = NULL;
		else
		{
			new_data = malloc(vec->elt_size * vec->size);
			if (!new_data)
			{
				ft_vecclear(vec);
				return (false);
			}
			ft_memcpy(new_data, vec->data, vec->elt_size * vec->size);
		}
		free(vec->data);
		vec->data = new_data;
		vec->capacity = vec->size;
	}
	return (true);
}
