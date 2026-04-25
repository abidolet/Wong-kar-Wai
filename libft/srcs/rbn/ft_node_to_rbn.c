/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_to_rbn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:54:22 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Converts a tree node base to its enclosing red-black tree node.
 * 
 * @param node Pointer to the base node.
 * @return Pointer to the enclosing red-black tree node.
 */
t_rbn	*ft_node_to_rbn(t_node *node)
{
	return ((t_rbn *)((char *)node - (char *)&((t_rbn *)0)->node));
}
