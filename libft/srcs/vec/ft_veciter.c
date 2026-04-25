/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veciter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 02:17:56 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/22 09:37:03 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"

void	ft_veciter(t_vector *vec, void (*f)(void *))
{
	char	*data;
	size_t	i;

	if (!vec || !f)
		return ;
	data = (char *)vec->data;
	i = 0;
	while (i < vec->size)
	{
		f(data + i * vec->elt_size);
		i++;
	}
}
