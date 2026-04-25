/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 08:56:16 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:06:07 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
#include <stdlib.h>

/**
 * @brief Clears and deletes the node and all its sub-nodes.
 * 
 * @param node	Pointer to the red-black tree node.
 * @param del	Function pointer to delete the node's data.
 */
void	ft_rbnclear(t_rbn *node, void (*del)(void *))
{
	if (ft_rbnis_nil(node))
		return ;
	ft_rbnclear(ft_rbnget_left(node), del);
	ft_rbnclear(ft_rbnget_right(node), del);
	ft_rbndel(node, del);
}
