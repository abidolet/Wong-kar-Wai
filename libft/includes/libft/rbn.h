/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:48:28 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 11:51:17 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBN_H
# define RBN_H

# include "libft/node.h"
# include <stddef.h>

typedef enum e_side
{
	LEFT = 0,
	RIGHT
}	t_side;

typedef enum e_rbtcolor
{
	RBT_BLACK = 0,
	RBT_RED
}	t_rbtcolor;

typedef struct s_rbn
{
	t_node	node;
	void	*data;
	t_rbtcolor	color;
}	t_rbn;

t_rbn	*ft_rbnnew(t_rbn *nil, void *data);
void	ft_rbndel(t_rbn *node, void (*del)(void *));
void	ft_rbnclear(t_rbn *node, void (*del)(void *));
bool	ft_rbnis_root(t_rbn *rbn);
bool	ft_rbnis_leaf(t_rbn *rbn);
bool	ft_rbnis_nil(t_rbn *rbn);
bool	ft_rbnis_red(t_rbn *rbn);
bool	ft_rbnis_black(t_rbn *rbn);
bool	ft_rbnis_left_child(t_rbn *rbn);
bool	ft_rbnis_right_child(t_rbn *rbn);
bool	ft_rbnis_triangle(t_rbn *rbn);
bool	ft_rbnis_line(t_rbn *rbn);
t_rbn	*ft_rbnget_left(t_rbn *rbn);
t_rbn	*ft_rbnget_right(t_rbn *rbn);
t_rbn	*ft_rbnget_parent(t_rbn *rbn);
void	*ft_rbnget_data(t_rbn *rbn);
t_rbtcolor	ft_rbnget_color(t_rbn *rbn);
t_rbn	*ft_rbnget_child(t_rbn *node, t_side side);
t_rbn	*ft_rbnget_grandparent(t_rbn *rbn);
t_rbn	*ft_rbnget_sibling(t_rbn *rbn);
t_rbn	*ft_rbnget_uncle(t_rbn *rbn);
void	ft_rbnset_left(t_rbn *rbn, t_rbn *new);
void	ft_rbnset_right(t_rbn *rbn, t_rbn *new);
void	ft_rbnset_parent(t_rbn *rbn, t_rbn *new);
void	ft_rbnset_data(t_rbn *rbn, void *data);
void	ft_rbnset_color(t_rbn *rbn, t_rbtcolor color);
void	ft_rbnrotate(t_rbn **root, t_rbn *node, t_side side);
void	ft_rbnrotate_left(t_rbn **root, t_rbn *node);
void	ft_rbnrotate_right(t_rbn **root, t_rbn *node);
t_rbn	*ft_node_to_rbn(t_node *node);
void	ft_rbnrecolor(t_rbn *rbn);
void	ft_rbnattach(t_rbn *parent, t_rbn *child, t_side side);
void	ft_rbndetach(t_rbn *node, t_rbn *nil);
void	ft_rbnreplace(t_rbn *old, t_rbn *new, void (*del)(void *));
t_rbn	*ft_rbnmin(t_rbn *node);
t_rbn	*ft_rbnmax(t_rbn *node);
t_rbn	*ft_rbnnext(t_rbn *node);

#endif
