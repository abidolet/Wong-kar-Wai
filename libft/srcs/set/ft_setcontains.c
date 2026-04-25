/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:16:39 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"

/**
 * @brief Check if the set contains an element
 * 
 * @param set The set to check
 * @param data The element data to find
 * @return bool True if the element exists, false otherwise
 */
bool	ft_setcontains(t_set *set, void *data)
{
	if (!set || !set->tree)
		return (false);
	return (!ft_rbnis_nil(ft_rbtfind(set->tree, data)));
}
