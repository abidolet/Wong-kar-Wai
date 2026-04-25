/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:29:14 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:51 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/set.h"

/**
 * @brief Iterate over the set and apply a function
 * 
 * @param set The set to iterate over
 * @param f The function to apply to each element
 * @return void
 */
void	ft_setiter(t_set *set, void (*f)(void *))
{
	if (!set || !set->tree || !f)
		return ;
	ft_rbtiter(set->tree, f);
}
