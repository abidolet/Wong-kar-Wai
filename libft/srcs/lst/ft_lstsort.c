/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:00:17 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 08:56:44 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/lst.h"

/**
 * @brief Helper function to merge two sorted lists.
 * @internal
 * @param a The first sorted list.
 * @param b The second sorted list.
 * @param cmp The comparison function to determine the order.
 * @return t_list* Returns the combined sorted list.
 */
static t_list	*merge(t_list *a, t_list *b, int (*cmp)(void *, void *))
{
	t_list	*res;

	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (cmp(a->content, b->content) <= 0)
	{
		res = a;
		res->next = merge(a->next, b, cmp);
	}
	else
	{
		res = b;
		res->next = merge(a, b->next, cmp);
	}
	return (res);
}

/**
 * @brief Sorts a linked list using the merge sort algorithm.
 * @internal
 * @param lst	The list to be sorted.
 * @param front	The address of the first half of the list.
 * @param back 	The address of the second half of the list.
 */
static void	split(t_list *lst, t_list **front, t_list **back)
{
	t_list	*slow;
	t_list	*fast;

	slow = lst;
	fast = lst->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = lst;
	*back = slow->next;
	slow->next = NULL;
}

/**
 * @brief Sorts a linked list in place using the merge sort algorithm.
 * 
 * @param lst	The list to be sorted.
 * @param cmp	The comparison function to determine the order of the elements.
 */
void	ft_lstsort(t_list **lst, int (*cmp)(void *, void *))
{
	t_list	*a;
	t_list	*b;

	if (!lst || !cmp || ft_lstsize(*lst) < 2)
		return ;
	split(*lst, &a, &b);
	ft_lstsort(&a, cmp);
	ft_lstsort(&b, cmp);
	*lst = merge(a, b, cmp);
}
