/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:28:47 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"
#include <stdlib.h>

/**
 * @brief Insert an element into the set
 * 
 * @param set The set to modify
 * @param data The element data to insert
 * @return void
 */
void	ft_setinsert(t_set *set, void *data)
{
	if (!set || !set->tree)
		return ;
	ft_rbtinsert(set->tree, data);
	if (!set->tree->root)
	{
		free(set->tree->nil);
		free(set->tree);
		set->tree = NULL;
	}
}
