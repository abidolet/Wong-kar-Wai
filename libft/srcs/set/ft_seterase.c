/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seterase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:18:27 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"

/**
 * @brief Remove an element from the set
 * 
 * @param set The set to modify
 * @param data The element data to remove
 * @return void
 */
void	ft_seterase(t_set *set, void *data)
{
	if (!set || !set->tree)
		return ;
	ft_rbtdelete(set->tree, data);
}
