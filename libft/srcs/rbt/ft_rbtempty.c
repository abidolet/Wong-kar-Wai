/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtempty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:49:58 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:36:36 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Returns a boolean indicating whether the tree is empty or not.
 * 
 * @param tree The tree to check.
 * @return true if the tree is empty, false otherwise.
 */
bool	ft_rbtempty(t_rbt *tree)
{
	return (tree->size == 0);
}
