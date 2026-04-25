/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapempty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:09:49 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 08:58:53 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"

/**
 * @brief Checks if a map is empty.
 * 
 * @param map The map to check.
 * @return True if the map is empty, false otherwise.
 */
bool	ft_mapempty(t_map *map)
{
	if (!map || !map->tree)
		return (true);
	return (ft_rbtempty(map->tree) == 0);
}
