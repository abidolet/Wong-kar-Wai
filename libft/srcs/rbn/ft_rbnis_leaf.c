/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnis_leaf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:07:34 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/18 16:06:05 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Checks if a red-black tree node is a leaf.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return True if leaf, otherwise false.
 * @note Here a leaf is defined as a node whose left and right children are nil.
 */
bool	ft_rbnis_leaf(t_rbn *rbn)
{
	return (ft_rbnis_nil(ft_rbnget_left(rbn))
		&& ft_rbnis_nil(ft_rbnget_right(rbn)));
}
