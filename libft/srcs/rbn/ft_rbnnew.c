/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 23:12:23 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/18 15:30:09 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
#include <stdlib.h>
/**
 * @brief Create a new node
 * 
 * @param nil	The nil node
 * @param data	The data to store in the node
 * @return The new node
 */
t_rbn	*ft_rbnnew(t_rbn *nil, void *data)
{
	t_rbn	*rbn;

	if (!nil)
		return (NULL);
	rbn = malloc(sizeof(t_rbn));
	if (!rbn)
		return (NULL);
	rbn->node.left = &nil->node;
	rbn->node.right = &nil->node;
	rbn->node.parent = &nil->node;
	rbn->data = data;
	rbn->color = RBT_RED;
	return (rbn);
}
