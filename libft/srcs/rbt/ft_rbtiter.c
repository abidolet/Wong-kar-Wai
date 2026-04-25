/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:52:17 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:40:37 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Iterates the tree and applies a function on the content of each node.
 * 
 * @param tree	The red-black tree to iterate.
 * @param f		The function to apply on each node's data.
 * @note The function is applied in order.
 */
void	ft_rbtiter(t_rbt *tree, void (*f)(void *))
{
	t_rbn	*node;

	node = ft_rbtmin(tree);
	while (node != tree->nil)
	{
		f(node->data);
		node = ft_rbnnext(node);
	}
}
