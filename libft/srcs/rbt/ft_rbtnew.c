/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:38:45 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:42:01 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"
#include <stdlib.h>

/**
 * @brief Create a new red-black tree.
 * 
 * @param cmp The function used to compare the data of the nodes.
 * @param del The function used to delete the data of the nodes.
 * @return A pointer to the new red-black tree, or NULL if the creation failed.
 */
t_rbt	*ft_rbtnew(
	int (*cmp)(const void *, const void *), void (*del)(void *))
{
	t_rbt	*tree;
	t_rbn	*nil;

	tree = malloc(sizeof(t_rbt));
	if (!tree)
		return (NULL);
	nil = malloc(sizeof(t_rbn));
	if (!nil)
	{
		free(tree);
		return (NULL);
	}
	ft_rbtinit(tree, nil, cmp, del);
	return (tree);
}
