/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:08:36 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"

/**
 * @brief Checks if there is an element with key in the map.
 * 
 * @param map Pointer to the map.
 * @param key Key value of the element to count.
 * @return true if there is such an element, false otherwise.
 */
bool	ft_mapcontains(t_map *map, void *key)
{
	t_rbn	*node;
	t_pair	dummy;

	if (!map || !map->tree || !key)
		return (false);
	dummy.key = key;
	node = ft_rbtfind(map->tree, &dummy);
	return (!ft_rbnis_nil(node));
}
