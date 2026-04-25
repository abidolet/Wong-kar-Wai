/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbndel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 08:56:16 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:06:15 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
#include <stdlib.h>

/**
 * @brief Deletes a single red-black tree node.
 * 
 * @param node	Pointer to the node to delete.
 * @param del	Function pointer to delete the node's data.
 */
void	ft_rbndel(t_rbn *node, void (*del)(void *))
{
	if (ft_rbnis_nil(node))
		return ;
	if (del)
		del(node->data);
	free(node);
}
