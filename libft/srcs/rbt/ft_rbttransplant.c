/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbttransplant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:04:20 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:46:53 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Replaces one subtree as a child of its parent with another subtree.
 * 
 * @param tree	The tree to transplant in.
 * @param old	The subtree to be replaced.
 * @param new	The subtree to replace with.
 */
void	ft_rbttransplant(t_rbt *tree, t_rbn *old, t_rbn *new)
{
	if (ft_rbnis_root(old))
		tree->root = new;
	else if (ft_rbnis_left_child(old))
		ft_rbnset_left(ft_rbnget_parent(old), new);
	else
		ft_rbnset_right(ft_rbnget_parent(old), new);
	ft_rbnset_parent(new, ft_rbnget_parent(old));
}
