/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:23:30 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 02:42:19 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"

void	ft_vecremove_if(t_vector *vec, int (*cmp)(void *))
{
	size_t	read;
	size_t	write;
	char	*data;

	if (!vec || !cmp)
		return ;
	read = 0;
	write = 0;
	data = (char *)vec->data;
	while (read < vec->size)
	{
		if (cmp(data + read * vec->elt_size) && vec->del)
			vec->del(data + read * vec->elt_size);
		else
		{
			if (read != write)
				ft_memmove(data + write * vec->elt_size,
					data + read * vec->elt_size, vec->elt_size);
			write++;
		}
		read++;
	}
	vec->size = write;
}
