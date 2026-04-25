/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:40:52 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:11 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

/**
 * @brief Reverses the order of the nodes in a list.
 * 
 * @param lst The list to reverse.
 * @return t_list* The new beginning of the list.
 */
t_list	*ft_lstreverse(t_list *lst)
{
	t_list	*res;
	t_list	*next;

	res = NULL;
	while (lst)
	{
		next = lst->next;
		lst->next = res;
		res = lst;
		lst = next;
	}
	return (res);
}
