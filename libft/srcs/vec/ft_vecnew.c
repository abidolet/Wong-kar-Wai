/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:02:34 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 18:13:06 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"
#include "libft/mem.h"
#include <stdlib.h>

t_vector	*ft_vecnew(size_t elt_size, void (*del)(void *))
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		return (NULL);
	ft_vecinit(vec, elt_size, del);
	return (vec);
}
