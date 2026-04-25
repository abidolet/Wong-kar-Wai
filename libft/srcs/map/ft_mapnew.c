/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:14:29 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:01:09 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"
#include <stdlib.h>
/**
 * @brief Creates a new map.
 * 
 * @param cmp The comparison function for keys.
 * @param del_key The deletion function for keys.
 * @param del_value The deletion function for values.
 * @return The new map, or NULL if allocation fails.
 */
t_map	*ft_mapnew(int (*cmp)(const void *, const void *),
	void (*del_key)(void *), void (*del_value)(void *))
{
	t_map	*map;

	if (!cmp)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->tree = ft_rbtnew(cmp, NULL);
	if (!map->tree)
	{
		free(map);
		return (NULL);
	}
	map->del_key = del_key;
	map->del_value = del_value;
	return (map);
}
