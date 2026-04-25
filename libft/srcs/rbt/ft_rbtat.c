/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:06:18 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:34:58 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"

/**
 * @brief Returns the node at the given index in the tree.
 * 
 * @param tree	The tree to search in
 * @param index	The index of the node to find
 * @return The node at the given index, nil if the index is out of bounds
 */
t_rbn	*ft_rbtat(t_rbt *tree, size_t index)
{
	t_rbn	*node;

	node = tree->root;
	while (!ft_rbnis_nil(node) && index--)
	{
		node = ft_rbnnext(node);
	}
	return (node);
}
