/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:00:00 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:11 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

/**
 * @brief Merges two linked lists by appending list 'b' at the end of list 'a'.
 * 
 * @param a The first list, to which the second will be appended.
 * @param b The second list.
 * @return t_list* The merged list.
 */
t_list	*ft_lstmerge(t_list *a, t_list *b)
{
	if (!a)
		return (b);
	ft_lstlast(a)->next = b;
	return (a);
}
