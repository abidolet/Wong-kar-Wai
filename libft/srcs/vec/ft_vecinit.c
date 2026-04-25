/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:02:34 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/mem.h"

void	ft_vecinit(t_vector *vec, size_t elt_size, void (*del)(void *))
{
	if (!vec)
		return ;
	ft_bzero(vec, sizeof(t_vector));
	vec->elt_size = elt_size;
	vec->del = del;
}
