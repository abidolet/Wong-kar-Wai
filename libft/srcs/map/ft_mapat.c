/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:05:12 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 08:58:04 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"

/**
 * @brief Returns a reference to the mapped value of the element based on a key.
 * 
 * @param map Pointer to the map.
 * @param key Key value of the element whose mapped value is accessed.
 * @return void* Pointer to the mapped value of the element based on the key.
 */
void	*ft_mapat(t_map *map, void *key)
{
	t_rbn	*node;
	t_pair	dummy;

	if (!map || !map->tree || !key)
		return (NULL);
	dummy.key = key;
	node = ft_rbtfind(map->tree, &dummy);
	if (ft_rbnis_nil(node))
		return (NULL);
	return (((t_pair *)ft_rbnget_data(node))->value);
}
