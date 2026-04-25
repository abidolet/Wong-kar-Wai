/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:58:29 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:48 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"
/**
 * @brief Find the minimum node in the tree
 * 
 * @param node The node to start searching from
 * @return The minimum node
 */
t_rbn	*ft_rbnmin(t_rbn *node)
{
	t_rbn	*left;

	left = ft_rbnget_left(node);
	while (!ft_rbnis_nil(left))
	{
		node = left;
		left = ft_rbnget_left(node);
	}
	return (node);
}
