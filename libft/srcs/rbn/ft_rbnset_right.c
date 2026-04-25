/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnset_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:27:24 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:34 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
/**
 * @brief Set the right child of a node
 * 
 * @param rbn The node to set right child for
 * @param new The new right child node
 * @return void
 */
void	ft_rbnset_right(t_rbn *rbn, t_rbn *new)
{
	rbn->node.right = &new->node;
	if (!ft_rbnis_nil(new))
		ft_rbnset_parent(new, rbn);
}
