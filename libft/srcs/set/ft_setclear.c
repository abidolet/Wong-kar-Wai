/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:14:04 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"
#include <stdlib.h>

/**
 * @brief Clear all elements from the set
 * 
 * @param set The set to clear
 * @return void
 */
void	ft_setclear(t_set *set)
{
	if (!set || !set->tree)
		return ;
	ft_rbtclear(set->tree);
	free(set->tree->nil);
	free(set->tree);
}
