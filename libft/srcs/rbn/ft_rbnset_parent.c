/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnset_parent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:27:24 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:40 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
/**
 * @brief Set the parent of a node
 * 
 * @param rbn The node to set parent for
 * @param new The new parent node
 * @return void
 */
void	ft_rbnset_parent(t_rbn *rbn, t_rbn *new)
{
	rbn->node.parent = &new->node;
}
