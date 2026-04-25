/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:02:47 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:37:57 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"
#include <stdlib.h>

/**
 * @brief Removes all nodes if the content matches the comparison function.
 * 
 * @param lst The address of a pointer to a node.
 * @param cmp The comparison function used to test the nodes.
 * @param free_fct The function used to free the 'content' of the removed nodes.
 */
void	ft_lstremove_if(
	t_list **lst, int (*cmp)(void *), void (*free_fct)(void *))
{
	t_list	*tmp;

	if (!lst || !cmp)
		return ;
	while (*lst)
	{
		tmp = *lst;
		if (cmp(tmp->content))
		{
			*lst = tmp->next;
			if (free_fct)
				free_fct(tmp->content);
			free(tmp);
		}
		else
			lst = &(*lst)->next;
	}
}
