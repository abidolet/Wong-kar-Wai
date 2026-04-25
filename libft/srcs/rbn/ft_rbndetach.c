/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbndetach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:29:35 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:06:19 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Detaches a node from its parent.
 * 
 * @param node	Pointer to the node to detach.
 * @param nil	Pointer to the nil node to replace it with.
 */
void	ft_rbndetach(t_rbn *node, t_rbn *nil)
{
	t_rbn	*parent;

	if (ft_rbnis_nil(node))
		return ;
	parent = ft_rbnget_parent(node);
	if (ft_rbnis_nil(parent))
		return ;
	if (ft_rbnis_left_child(node))
		ft_rbnset_left(parent, nil);
	else
		ft_rbnset_right(parent, nil);
}
