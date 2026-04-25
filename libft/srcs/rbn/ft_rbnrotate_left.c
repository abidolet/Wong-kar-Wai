/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnrotate_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:57:14 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:16 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"
/**
 * @brief Rotate a node left in the tree
 * 
 * @param root The root of the tree
 * @param node The node to rotate
 * @return void
 */
void	ft_rbnrotate_left(t_rbn **root, t_rbn *node)
{
	t_rbn	*right;
	t_rbn	*parent;

	right = ft_rbnget_right(node);
	parent = ft_rbnget_parent(node);
	ft_rbnset_right(node, ft_rbnget_left(right));
	ft_rbnset_parent(right, parent);
	if (ft_rbnis_nil(parent))
		*root = right;
	else if (ft_rbnis_left_child(node))
		ft_rbnset_left(parent, right);
	else
		ft_rbnset_right(parent, right);
	ft_rbnset_left(right, node);
}
