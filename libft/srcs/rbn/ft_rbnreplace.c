/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:04:31 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:44 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
#include <stdlib.h>
/**
 * @brief Replace a node with another node
 * 
 * @param old The old node to replace
 * @param new The new node
 * @param del Function to delete the old node's data
 * @return void
 */
void	ft_rbnreplace(t_rbn *old, t_rbn *new, void (*del)(void *))
{
	t_rbn	*parent;

	if (ft_rbnis_nil(old))
		return ;
	parent = ft_rbnget_parent(old);
	if (!ft_rbnis_nil(parent))
	{
		if (ft_rbnis_left_child(old))
			ft_rbnset_left(parent, new);
		else
			ft_rbnset_right(parent, new);
	}
	if (!ft_rbnis_nil(new))
		ft_rbndel(old, del);
}
