/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnget_sibling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:49:08 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Retrieves the sibling of a red-black tree node.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return Pointer to the sibling node.
 */
t_rbn	*ft_rbnget_sibling(t_rbn *rbn)
{
	if (ft_rbnis_left_child(rbn))
		return (ft_rbnget_right(ft_rbnget_parent(rbn)));
	return (ft_rbnget_left(ft_rbnget_parent(rbn)));
}
