/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:58:44 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 08:57:16 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstdestroy(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstmerge(t_list *a, t_list *b);
t_list	*ft_lstnew(void *content);
void	ft_lstremove_if(
			t_list **lst, int (*cmp)(void *), void (*free_fct)(void *));
t_list	*ft_lstreverse(t_list *lst);
size_t	ft_lstsize(t_list *lst);
void	ft_lstsort(t_list **lst, int (*cmp)(void *, void *));

#endif
