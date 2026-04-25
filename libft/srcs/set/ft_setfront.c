/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfront.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:23:35 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"

/**
 * @brief Get the minimum element in the set
 * 
 * @param set The set to access
 * @return void* The minimum element data, or NULL if empty
 */
void	*ft_setfront(t_set *set)
{
	if (!set || !set->tree || ft_setempty(set))
		return (NULL);
	return (ft_rbtmin(set->tree)->data);
}
