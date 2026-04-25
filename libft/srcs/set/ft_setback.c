/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:12:03 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"

/**
 * @brief Get the maximum element in the set
 * 
 * @param set The set to access
 * @return void* The maximum element data, or NULL if empty
 */
void	*ft_setback(t_set *set)
{
	if (!set || !set->tree || ft_rbtempty(set->tree))
		return (NULL);
	return (ft_rbtmax(set->tree)->data);
}
