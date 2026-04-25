/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnget_parent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:48:50 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Retrieves the parent of a red-black tree node.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return Pointer to the parent node.
 */
t_rbn	*ft_rbnget_parent(t_rbn *rbn)
{
	return (ft_node_to_rbn(rbn->node.parent));
}
