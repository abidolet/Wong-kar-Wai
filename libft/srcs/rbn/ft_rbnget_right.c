/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnget_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:49:02 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Retrieves the right child of a red-black tree node.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return Pointer to the right child node.
 */
t_rbn	*ft_rbnget_right(t_rbn *rbn)
{
	return (ft_node_to_rbn(rbn->node.right));
}
