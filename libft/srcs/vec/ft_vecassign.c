/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecassign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:54:40 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/mem.h"

void	ft_vecassign(t_vector *dest, t_vector *src)
{
	if (!dest || !src)
		return ;
	ft_vecclear(dest);
	dest->elt_size = src->elt_size;
	ft_vecreserve(dest, src->capacity);
	if (!dest->data && src->capacity > 0)
		return ;
	if (src->size > 0)
		ft_memcpy(dest->data, src->data, src->size * src->elt_size);
	dest->size = src->size;
}
