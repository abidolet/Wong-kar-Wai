/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:29:03 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:45:34 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_H
# define RBT_H

# include "libft/rbn.h"

typedef struct s_rbt
{
	struct s_rbn	*root;
	struct s_rbn	*nil;
	size_t			size;
	int				(*cmp)(const void *, const void *);
	void			(*del)(void *);
}	t_rbt;

t_rbn	*ft_rbtat(t_rbt *tree, size_t index);
void	ft_rbtclear(t_rbt *tree);
void	ft_rbtdelete(t_rbt *tree, void *data);
bool	ft_rbtempty(t_rbt *tree);
void	ft_rbterase(t_rbt *tree, t_rbn *node);
t_rbn	*ft_rbtfind(t_rbt *tree, const void *data);
size_t	ft_rbtheight(t_rbt *tree);
void	ft_rbtinit(t_rbt *tree, t_rbn *nil,
			int (*cmp)(const void *, const void *), void (*del)(void *));
void	ft_rbtinsert(t_rbt *tree, void *data);
void	ft_rbtiter(t_rbt *tree, void (*f)(void *));
t_rbn	*ft_rbtmax(t_rbt *tree);
t_rbn	*ft_rbtmin(t_rbt *tree);
t_rbt	*ft_rbtnew(
			int (*cmp)(const void *, const void *), void (*del)(void *));
size_t	ft_rbtsize(t_rbt *tree);
void	ft_rbttransplant(t_rbt *tree, t_rbn *old, t_rbn *new);

#endif
