/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:45:58 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 11:59:59 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Deletes the node with the given data from the tree, if it exists.
 * 
 * @param tree The tree to delete from.
 * @param data The data of the node to delete.
 * @note If no node with the given data exists, the tree is not modified.
 */
void	ft_rbtdelete(t_rbt *tree, void *data)
{
	t_rbn	*node;

	node = ft_rbtfind(tree, data);
	if (ft_rbnis_nil(node))
		return ;
	ft_rbterase(tree, node);
}
