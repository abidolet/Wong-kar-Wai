/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:57:25 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/22 12:21:20 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft/rbt.h"
# include <sys/types.h>

typedef struct s_pair
{
	void	*key;
	void	*value;
}	t_pair;

typedef struct s_map
{
	t_rbt	*tree;
	void	(*del_key)(void *);
	void	(*del_value)(void *);
}	t_map;

void	*ft_mapat(t_map *map, void *key);
void	ft_mapclear(t_map *map);
bool	ft_mapcontains(t_map *map, void *key);
bool	ft_mapempty(t_map *map);
void	ft_maperase(t_map *map, void *key);
t_pair	*ft_mapfind(t_map *map, void *key);
void	ft_mapinsert(t_map *map, void *key, void *value);
void	ft_mapiter(t_map *map, void (*f)(void *));
t_map	*ft_mapnew(int (*cmp)(const void *, const void *),
			void (*del_key)(void *), void (*del_value)(void *));
size_t	ft_mapsize(t_map *map);

#endif
