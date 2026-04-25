/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:13:27 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:10:01 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"
#include <stdlib.h>

/**
 * @brief Insert an element into the map or modify the value if the key exists.
 * 
 * @param map Pointer to the map.
 * @param key Key value to insert.
 * @param value Mapped value to insert.
 * @note If a malloc fails, all values are freed. Please free the map
 */
void	ft_mapinsert(t_map *map, void *key, void *value)
{
	t_pair	*pair;

	if (!map || !map->tree || !key || !value)
		return ;
	pair = malloc(sizeof(t_pair));
	if (!pair)
		return ;
	pair->key = key;
	pair->value = value;
	ft_rbtinsert(map->tree, pair);
}
