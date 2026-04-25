/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:57:43 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/mem.h"
#include <stdlib.h>

void	ft_vecclear(t_vector *vec)
{
	const char	*data = (const char *)vec->data;
	size_t		i;

	if (!vec || !vec->data)
		return ;
	if (vec->del)
	{
		i = 0;
		while (i < vec->size)
		{
			if (vec->del)
				vec->del((void *)(data + i * vec->elt_size));
			i++;
		}
	}
	free(vec->data);
	ft_bzero(vec, sizeof(t_vector));
}
