/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecpush_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:04:08 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 01:59:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"
#include <stdint.h>

bool	ft_vecpush_back(t_vector *vec, void *element)
{
	if (!vec)
		return (false);
	return (ft_vecinsert(vec, vec->size, element));
}
