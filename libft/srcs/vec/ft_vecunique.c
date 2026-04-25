/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecunique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:12:10 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 11:14:16 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/algo.h"

void	ft_vecunique(t_vector *vec, int (*cmp)(const void *, const void *))
{
	ssize_t	size;

	if (!vec || !cmp)
		return ;
	size = ft_unique((t_algo){vec->data, vec->size, vec->elt_size, cmp});
	if (size >= 0)
		vec->size = (size_t)size;
}
