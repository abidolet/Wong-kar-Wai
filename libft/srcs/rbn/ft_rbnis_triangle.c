/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnis_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:41:20 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:30:45 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Checks if a node and its parent form a triangle.
 * @param rbn Pointer to the red-black tree node.
 * @return True if they form a triangle, otherwise false.
 * @note A triangle is when the node is the opposite child of its parent
 */
bool	ft_rbnis_triangle(t_rbn *rbn)
{
	t_rbn	*parent;

	parent = ft_rbnget_parent(rbn);
	return ((ft_rbnis_left_child(rbn) && ft_rbnis_right_child(parent))
		|| (ft_rbnis_right_child(rbn) && ft_rbnis_left_child(parent)));
}
