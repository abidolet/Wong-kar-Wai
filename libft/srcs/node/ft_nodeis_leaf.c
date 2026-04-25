/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeis_leaf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:25:37 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:11 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/node.h"

/**
 * @brief Checks if a given node is a leaf (has no children).
 * 
 * @param node The node to check.
 * @return true if the node is a leaf, false otherwise.
 */
bool	ft_nodeis_leaf(t_node *node)
{
	return (node && !node->left && !node->right);
}
