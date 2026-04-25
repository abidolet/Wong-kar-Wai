/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:58:29 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:52 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"
/**
 * @brief Find the maximum node in the tree
 * 
 * @param node The node to start searching from
 * @return The maximum node
 */
t_rbn	*ft_rbnmax(t_rbn *node)
{
	t_rbn	*right;

	right = ft_rbnget_right(node);
	while (!ft_rbnis_nil(right))
	{
		node = right;
		right = ft_rbnget_right(node);
	}
	return (node);
}
