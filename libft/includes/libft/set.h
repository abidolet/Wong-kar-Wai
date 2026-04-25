/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:52:38 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/21 19:28:36 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "libft/rbt.h"
# include <sys/types.h>

typedef struct s_set
{
	t_rbt	*tree;
}	t_set;

void	*ft_setat(t_set *set, size_t index);
void	*ft_setback(t_set *set);
void	ft_setclear(t_set *set);
bool	ft_setcontains(t_set *set, void *data);
bool	ft_setempty(t_set *set);
void	ft_seterase(t_set *set, void *data);
ssize_t	ft_setfind(t_set *set, void *data);
void	*ft_setfront(t_set *set);
void	ft_setinsert(t_set *set, void *data);
void	ft_setiter(t_set *set, void (*f)(void *));
t_set	*ft_setnew(
			int (*cmp)(const void *, const void *), void (*del)(void *));
size_t	ft_setsize(t_set *set);

#endif
