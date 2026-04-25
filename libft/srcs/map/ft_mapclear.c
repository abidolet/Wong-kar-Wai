/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:06:46 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 08:58:57 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"
#include <stdlib.h>

/**
 * @brief Clears and frees all elements in the map.
 * 
 * @param map The map to clear.
 */
void	ft_mapclear(t_map *map)
{
	t_rbn	*node;
	t_pair	*pair;

	if (!map || !map->tree)
		return ;
	node = ft_rbtmin(map->tree);
	while (!ft_rbnis_nil(node))
	{
		pair = (t_pair *)node->data;
		if (map->del_key)
			map->del_key(pair->key);
		if (map->del_value)
			map->del_value(pair->value);
		free(pair);
		node = ft_rbnnext(node);
	}
	ft_rbtclear(map->tree);
	free(map->tree);
	free(map->tree);
}
