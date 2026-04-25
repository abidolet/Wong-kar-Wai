/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:58:29 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:41:10 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Find the maximum node in a red-black tree.
 * 
 * @param tree The red-black tree to search.
 * @return The maximum node in the tree, or nil if the tree is empty.
 */
t_rbn	*ft_rbtmax(t_rbt *tree)
{
	return (ft_rbnmax(tree->root));
}
