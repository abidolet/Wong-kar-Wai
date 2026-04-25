/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maperase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:10:55 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"
#include <stdlib.h>

/**
 * @brief Removes from the map container the element associated with key.
 * 
 * @param map Pointer to the map.
 * @param key Key value of the element to remove.
 */
void	ft_maperase(t_map *map, void *key)
{
	t_rbn	*node;
	t_pair	dummy;
	t_pair	*pair;

	if (!map || !map->tree || !key)
		return ;
	dummy.key = key;
	node = ft_rbtfind(map->tree, &dummy);
	if (ft_rbnis_nil(node))
		return ;
	pair = (t_pair *)ft_rbnget_data(node);
	ft_rbterase(map->tree, node);
	if (map->del_key)
		map->del_key(pair->key);
	if (map->del_value)
		map->del_value(pair->value);
	free(pair);
}
