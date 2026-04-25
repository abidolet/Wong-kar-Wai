/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnset_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:27:24 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:30 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
/**
 * @brief Set the left child of a node
 * 
 * @param rbn The node to set left child for
 * @param new The new left child node
 * @return void
 */
void	ft_rbnset_left(t_rbn *rbn, t_rbn *new)
{
	rbn->node.left = &new->node;
	if (!ft_rbnis_nil(new))
		ft_rbnset_parent(new, rbn);
}
