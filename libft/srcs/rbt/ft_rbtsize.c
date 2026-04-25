/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:05:49 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:42:32 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Returns the size of the tree.
 * 
 * @param tree The tree to get the size of.
 * @return The size of the tree.
 */
size_t	ft_rbtsize(t_rbt *tree)
{
	return (tree->size);
}
