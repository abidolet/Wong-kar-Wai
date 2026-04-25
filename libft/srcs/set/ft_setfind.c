/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:19:15 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"

/**
 * @brief Find the index of an element in the set
 * 
 * @param set The set to search
 * @param data The element data to find
 * @return ssize_t The index of the element, or -1 if not found
 */
ssize_t	ft_setfind(t_set *set, void *data)
{
	t_rbn	*node;
	ssize_t	res;

	if (!set || !set->tree)
		return (-1);
	node = ft_rbtmin(set->tree);
	res = 0;
	while (!ft_rbnis_nil(node))
	{
		if (set->tree->cmp(node->data, data) == 0)
			return (res);
		node = ft_rbnnext(node);
		res++;
	}
	return (-1);
}
