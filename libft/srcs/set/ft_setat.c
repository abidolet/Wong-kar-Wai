/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:06:18 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"

/**
 * @brief Get the element at a specific index
 * 
 * @param set The set to access
 * @param index The index of the element
 * @return void* The element data, or NULL if out of bounds
 */
void	*ft_setat(t_set *set, size_t index)
{
	if (!set || !set->tree || index >= ft_setsize(set))
		return (NULL);
	return (ft_rbtat(set->tree, index)->data);
}
