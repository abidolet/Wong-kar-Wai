/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnget_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:20:49 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:06:27 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Gets the child of a red-black tree node on a specified side.
 * 
 * @param node	Pointer to the red-black tree node.
 * @param side	The side (LEFT or RIGHT).
 * @return Pointer to the child node.
 */
t_rbn	*ft_rbnget_child(t_rbn *node, t_side side)
{
	if (side == LEFT)
		return (ft_rbnget_left(node));
	return (ft_rbnget_right(node));
}
