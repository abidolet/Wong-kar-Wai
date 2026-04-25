/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:29:39 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"
#include <stdlib.h>

/**
 * @brief Creates a new set.
 * 
 * @param cmp A pointer to the comparison function used to order the set elements.
 * @param del A pointer to the deletion function used to destroy the set elements.
 * @return A block of memory allocated for the new set.
 */
t_set	*ft_setnew(
	int (*cmp)(const void *, const void *), void (*del)(void *))
{
	t_set	*set;

	if (!cmp)
		return (NULL);
	set = malloc(sizeof(t_set));
	if (!set)
		return (NULL);
	set->tree = ft_rbtnew(cmp, del);
	if (!set->tree)
	{
		free(set);
		return (NULL);
	}
	return (set);
}
