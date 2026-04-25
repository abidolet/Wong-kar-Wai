/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:16:54 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 11:26:27 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/algo.h"

void	ft_vecrotate(t_vector *vec, size_t k, int direction)
{
	if (!vec)
		return ;
	ft_rotate((t_algo)
	{
		vec->data,
		vec->size,
		vec->elt_size,
		NULL
	}, k, direction);
}
