/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnrotate_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:57:14 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:20 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"
/**
 * @brief Rotate a node right in the tree
 * 
 * @param root The root of the tree
 * @param node The node to rotate
 * @return void
 */
void	ft_rbnrotate_right(t_rbn **root, t_rbn *node)
{
	t_rbn	*left;
	t_rbn	*parent;

	left = ft_rbnget_left(node);
	parent = ft_rbnget_parent(node);
	ft_rbnset_left(node, ft_rbnget_right(left));
	ft_rbnset_parent(left, parent);
	if (ft_rbnis_nil(parent))
		*root = left;
	else if (ft_rbnis_left_child(node))
		ft_rbnset_left(parent, left);
	else
		ft_rbnset_right(parent, left);
	ft_rbnset_right(left, node);
}
