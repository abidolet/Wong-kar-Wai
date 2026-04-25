/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:59:24 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
/**
 * @brief Rotate a node in the tree
 * 
 * @param root The root of the tree
 * @param node The node to rotate
 * @param side The direction to rotate
 * @return void
 */
void	ft_rbnrotate(t_rbn **root, t_rbn *node, t_side side)
{
	if (side == LEFT)
		ft_rbnrotate_left(root, node);
	else
		ft_rbnrotate_right(root, node);
}
