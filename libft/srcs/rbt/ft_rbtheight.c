/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtheight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:42:47 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 13:55:40 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Returns the height of the tree.
 * 
 * @param tree The tree to get the height of.
 * @return size_t The height of the tree.
 */
size_t	ft_rbtheight(t_rbt *tree)
{
	size_t	height;
	t_rbn	*node;

	height = 0;
	node = tree->root;
	while (node != tree->nil)
	{
		height++;
		node = ft_rbnget_left(node);
	}
	return (height);
}
