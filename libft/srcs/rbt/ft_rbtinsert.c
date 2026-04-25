/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:58:14 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:36:56 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

/**
 * @brief Update relatives of the node.
 * 
 * @param node			The node for which to update relatives.
 * @param parent		Pointer to the parent node.
 * @param grandparent	Pointer to the grandparent node.
 * @param uncle			Pointer to the uncle node.
 */
static void	update_relatives(t_rbn *node, t_rbn **parent, t_rbn **grandparent,
	t_rbn **uncle)
{
	*parent = ft_rbnget_parent(node);
	*grandparent = ft_rbnget_grandparent(node);
	*uncle = ft_rbnget_uncle(node);
}

/**
 * @brief Rebalance the red-black tree after insertion of a node.
 * 
 * @param tree	A red-black tree to rebalance.
 * @param node	The node that was inserted.
 * @param side	The side of the parent node.
 */
static void	fixup(t_rbt *tree, t_rbn **node, t_side side)
{
	t_rbn	*parent;
	t_rbn	*grandparent;
	t_rbn	*uncle;

	update_relatives(*node, &parent, &grandparent, &uncle);
	if (ft_rbnis_red(uncle))
	{
		ft_rbnset_color(parent, RBT_BLACK);
		ft_rbnset_color(grandparent, RBT_RED);
		ft_rbnrecolor(uncle);
		*node = grandparent;
	}
	else
	{
		if (ft_rbnis_triangle(*node))
		{
			*node = parent;
			ft_rbnrotate(&tree->root, *node, side);
			update_relatives(*node, &parent, &grandparent, &uncle);
		}
		ft_rbnset_color(parent, RBT_BLACK);
		ft_rbnset_color(grandparent, RBT_RED);
		ft_rbnrotate(&tree->root, grandparent, !side);
	}
}

/**
 * @brief Inserts a new node with the given data into the red-black tree.
 * 
 * @param tree		The red-black tree to insert into.
 * @param data		The data for the new node.
 * @param current	Pointer to the current node.
 * @param parent	Pointer to the parent node.
 */
static void	find_pos(t_rbt *tree, void *data, t_rbn **current, t_rbn **parent)
{
	int		cmp;

	*current = tree->root;
	*parent = tree->nil;
	while (*current != tree->nil)
	{
		*parent = *current;
		cmp = tree->cmp(data, ft_rbnget_data(*current));
		if (cmp == 0)
			break ;
		else if (cmp < 0)
			*current = ft_rbnget_left(*current);
		else
			*current = ft_rbnget_right(*current);
	}
}

/**
 * @brief Attaches a new node with the given data to the red-black tree.
 * 
 * @param tree	The red-black tree to attach to.
 * @param data	The data for the new node.
 * @return t_rbn* The new node if it was attached, nil if not.
 */
static t_rbn	*attach_to_tree(t_rbt *tree, void *data)
{
	t_rbn	*new;
	t_rbn	*current;
	t_rbn	*parent;

	find_pos(tree, data, &current, &parent);
	if (current != tree->nil)
	{
		ft_rbnset_data(current, data);
		return (tree->nil);
	}
	new = ft_rbnnew(tree->nil, data);
	if (!new)
	{
		ft_rbtclear(tree);
		return (tree->nil);
	}
	if (ft_rbnis_nil(parent))
		tree->root = new;
	else if (tree->cmp(data, ft_rbnget_data(parent)) < 0)
		ft_rbnattach(parent, new, LEFT);
	else
		ft_rbnattach(parent, new, RIGHT);
	return (new);
}

/**
 * @brief Inserts a new node with the given data into the red-black tree.
 * 
 * @param tree	The red-black tree to insert into.
 * @param data	The data for the new node.
 * @note If a node with the given data already exists, its data is updated.
 * @note If a malloc fails, the tree is cleared. Please free nil then the tree.
 */
void	ft_rbtinsert(t_rbt *tree, void *data)
{
	t_rbn	*new;

	new = attach_to_tree(tree, data);
	if (ft_rbnis_nil(new))
		return ;
	while (!ft_rbnis_root(new) && ft_rbnis_red(ft_rbnget_parent(new)))
		fixup(tree, &new, !ft_rbnis_left_child(ft_rbnget_parent(new)));
	ft_rbnset_color(tree->root, RBT_BLACK);
	tree->size++;
}
