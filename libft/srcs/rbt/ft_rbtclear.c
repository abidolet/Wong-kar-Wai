/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:35:07 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:35:34 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Deletes and frees the given tree and every successor of that tree.
 * 
 * @param tree The tree to clear.
 */
void	ft_rbtclear(t_rbt *tree)
{
	if (!ft_rbnis_nil(tree->root))
		ft_rbnclear(tree->root, tree->del);
	tree->root = NULL;
	tree->size = 0;
}
