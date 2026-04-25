/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecerase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:01:44 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/mem.h"

void	ft_vecerase(t_vector *vec, size_t index)
{
	const char	*data;
	void		*dest;
	void		*src;
	size_t		n;

	if (!vec || index >= vec->size)
		return ;
	data = (const char *)vec->data;
	if (vec->del)
		vec->del((char *)data + index * vec->elt_size);
	dest = (void *)(data + index * vec->elt_size);
	src = (void *)(data + (index + 1) * vec->elt_size);
	n = (vec->size - index - 1) * vec->elt_size;
	ft_memmove(dest, src, n);
	vec->size--;
}
