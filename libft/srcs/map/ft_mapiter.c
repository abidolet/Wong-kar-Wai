/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:14:22 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/map.h"

/**
 * @brief Iterates through the map and applies a function to every pair.
 * 
 * @param map Pointer to the map.
 * @param f Function to apply to each element's pair.
 */
void	ft_mapiter(t_map *map, void (*f)(void *))
{
	if (!map || !map->tree || !f)
		return ;
	ft_rbtiter(map->tree, f);
}
