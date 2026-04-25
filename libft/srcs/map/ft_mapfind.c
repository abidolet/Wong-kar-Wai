/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:11:08 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 08:59:33 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"

/**
 * @brief Searches the map for an element based on the provided key.
 * 
 * @param map Pointer to the map.
 * @param key Key to be searched for.
 * @return t_pair* Pointer to the element if found, otherwise NULL.
 */
t_pair	*ft_mapfind(t_map *map, void *key)
{
	t_rbn	*node;
	t_pair	dummy;

	if (!map || !map->tree || !key)
		return (NULL);
	dummy.key = key;
	node = ft_rbtfind(map->tree, &dummy);
	if (ft_rbnis_nil(node))
		return (NULL);
	return ((t_pair *)ft_rbnget_data(node));
}
