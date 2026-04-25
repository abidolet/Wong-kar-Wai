/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnis_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:41:20 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:26:54 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Checks if a node and its parent form a line.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return True if they form a line, otherwise false.
 * @note A line is when the node and its parent are both left or right children.
 */
bool	ft_rbnis_line(t_rbn *rbn)
{
	t_rbn	*parent;

	parent = ft_rbnget_parent(rbn);
	return ((ft_rbnis_left_child(rbn) && ft_rbnis_left_child(parent))
		|| (ft_rbnis_right_child(rbn) && ft_rbnis_right_child(parent)));
}
