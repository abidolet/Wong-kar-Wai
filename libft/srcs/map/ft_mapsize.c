/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:14:47 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:01:19 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"
/**
 * @brief Returns the number of elements in the map.
 * 
 * @param map The map to check.
 * @return The size of the map.
 */
size_t	ft_mapsize(t_map *map)
{
	if (!map || !map->tree)
		return (0);
	return (ft_rbtsize(map->tree));
}
