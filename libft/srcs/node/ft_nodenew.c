/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:40:21 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:00:06 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/node.h"
#include "libft/mem.h"

/**
 * @brief Allocates and returns a new empty node.
 * 
 * @return t_node* Pointer to the newly allocated node, NULL if allocation fails.
 */
t_node	*ft_nodenew(void)
{
	return (ft_calloc(1, sizeof(t_node)));
}
