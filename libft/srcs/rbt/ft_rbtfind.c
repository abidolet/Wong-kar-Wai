/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:03:26 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 11:47:58 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Finds a node in the red-black tree that matches the given data.
 * 
 * @param tree The red-black tree to search in.
 * @param data The data to search for.
 * @return A pointer to the node containing the data, nil if not found.
 */
t_rbn	*ft_rbtfind(t_rbt *tree, const void *data)
{
	t_rbn	*current;
	int		cmp;

	current = tree->root;
	while (current != tree->nil)
	{
		cmp = tree->cmp(data, ft_rbnget_data(current));
		if (cmp == 0)
			break ;
		else if (cmp < 0)
			current = ft_rbnget_left(current);
		else
			current = ft_rbnget_right(current);
	}
	return (current);
}
