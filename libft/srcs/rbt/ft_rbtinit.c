/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:41:29 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 11:51:35 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Initializes a red-black tree.
 * 
 * @param tree	The red-black tree to initialize.
 * @param nil	The sentinel node to use as the nil node of the tree.
 * @param cmp	The comparison function to use for comparing node data.
 * @param del	The deletion function to use for freeing node data.
 * @note The tree and nil must be allocated before calling this function.
 */
void	ft_rbtinit(t_rbt *tree, t_rbn *nil,
	int (*cmp)(const void *, const void *), void (*del)(void *))
{
	if (!tree || !nil)
		return ;
	nil->node.left = &nil->node;
	nil->node.right = &nil->node;
	nil->node.parent = &nil->node;
	nil->data = NULL;
	nil->color = RBT_BLACK;
	tree->nil = nil;
	tree->root = nil;
	tree->size = 0;
	tree->cmp = cmp;
	tree->del = del;
}
