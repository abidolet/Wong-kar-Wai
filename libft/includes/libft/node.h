/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:49:16 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/17 22:56:16 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <stdbool.h>

typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*parent;
}	t_node;

t_node	*ft_nodenew(void);
bool	ft_nodeis_root(t_node *node);
bool	ft_nodeis_leaf(t_node *node);

#endif
