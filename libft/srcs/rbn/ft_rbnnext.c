/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:53:36 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:57 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
/**
 * @brief Find the next node in the tree
 * 
 * @param node The node to start from
 * @return The next node
 */
t_rbn	*ft_rbnnext(t_rbn *node)
{
	t_rbn	*parent;

	if (ft_rbnis_nil(node))
		return (node);
	if (!ft_rbnis_nil(ft_rbnget_right(node)))
		return (ft_rbnmin(ft_rbnget_right(node)));
	parent = ft_rbnget_parent(node);
	while (!ft_rbnis_nil(parent) && node == ft_rbnget_right(parent))
	{
		node = parent;
		parent = ft_rbnget_parent(node);
	}
	return (parent);
}
