/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecreverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:54:33 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/algo.h"

void	ft_vecreverse(t_vector *vec)
{
	if (!vec || !vec->data || vec->size <= 1)
		return ;
	ft_reverse((t_algo)
	{
		vec->data,
		vec->size,
		vec->elt_size,
		NULL
	}, 0, vec->size - 1);
}
