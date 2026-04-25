/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbterase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:46:35 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 12:00:30 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbt.h"

static void	fixup(t_rbn **root, t_rbn *x);

/**
 * @brief Fixup the cases 2-4 of the rebalancing after deletion.
 * 
 * @param root		Root of the tree.
 * @param sibling	Sibling of the node to fixup.
 * @param parent	Parent of the node to fixup.
 * @param side		Side of the node to fixup.
 */
static void	fixup_other_cases(t_rbn **root, t_rbn *sibling, t_rbn *parent,
	t_side side)
{
	t_rbn	*near;
	t_rbn	*far;

	near = ft_rbnget_child(sibling, side);
	far = ft_rbnget_child(sibling, !side);
	if (ft_rbnis_black(near) && ft_rbnis_black(far))
	{
		ft_rbnset_color(sibling, RBT_RED);
		fixup(root, parent);
	}
	else
	{
		if (ft_rbnis_red(near) && ft_rbnis_black(far))
		{
			ft_rbnrotate(root, sibling, !side);
			ft_rbnset_color(near, RBT_BLACK);
			ft_rbnset_color(sibling, RBT_RED);
			sibling = near;
			far = ft_rbnget_child(sibling, !side);
		}
		ft_rbnrotate(root, parent, side);
		ft_rbnset_color(sibling, ft_rbnget_color(parent));
		ft_rbnset_color(parent, RBT_BLACK);
		ft_rbnset_color(far, RBT_BLACK);
	}
}

/**
 * @brief Fixup the case 1 of the rebalancing after deletion.
 * 
 * @param root		Root of the tree.
 * @param sibling	Sibling of the node to fixup.
 * @param parent	Parent of the node to fixup.
 * @param side		Side of the node to fixup.
 * @note This function modifies sibling in place.
 */
static void	fixup_case1(
	t_rbn **root, t_rbn **sibling, t_rbn *parent, t_side side)
{
	if (ft_rbnis_red(*sibling))
	{
		ft_rbnrotate(root, parent, side);
		ft_rbnset_color(*sibling, RBT_BLACK);
		ft_rbnset_color(parent, RBT_RED);
		*sibling = ft_rbnget_child(parent, !side);
	}
}

/**
 * @brief Rebalance the tree after deletion.
 * 
 * @param root	Root of the tree.
 * @param node	Node to start the fixup from.
 */
static void	fixup(t_rbn **root, t_rbn *node)
{
	t_side	side;
	t_rbn	*parent;
	t_rbn	*sibling;

	if (ft_rbnis_nil(node) || ft_rbnis_root(node))
		return ;
	if (ft_rbnis_red(node))
	{
		ft_rbnset_color(node, RBT_BLACK);
		return ;
	}
	side = ft_rbnis_right_child(node);
	parent = ft_rbnget_parent(node);
	sibling = ft_rbnget_child(parent, !side);
	fixup_case1(root, &sibling, parent, side);
	fixup_other_cases(root, sibling, parent, side);
}

/**
 * @brief Replace the node to erase by its sucessor.
 * 
 * @param tree	The tree to modify.
 * @param z		Node to replace.
 * @param y		Node to replace z by.
 * @return t_rbn* The node to fixup after replacement.
 */
static t_rbn	*replace_node(t_rbt *tree, t_rbn *z, t_rbn *y)
{
	t_rbn	*x;

	x = ft_rbnget_right(y);
	if (ft_rbnget_parent(y) == z)
		ft_rbnset_parent(x, y);
	else
	{
		ft_rbttransplant(tree, y, x);
		ft_rbnset_right(y, ft_rbnget_right(z));
		ft_rbnset_parent(ft_rbnget_right(z), y);
	}
	ft_rbttransplant(tree, z, y);
	ft_rbnset_left(y, ft_rbnget_left(z));
	ft_rbnset_parent(ft_rbnget_left(z), y);
	ft_rbnset_color(y, z->color);
	return (x);
}

/**
 * @brief Erase a node from the tree and rebalance it.
 * 
 * @param tree	The tree to modify.
 * @param z		Node to erase.
 */
void	ft_rbterase(t_rbt *tree, t_rbn *z)
{
	t_rbn		*x;
	t_rbn		*y;
	t_rbtcolor	original_color;

	original_color = z->color;
	if (ft_rbnis_nil(ft_rbnget_left(z)))
	{
		x = ft_rbnget_right(z);
		ft_rbttransplant(tree, z, x);
	}
	else if (ft_rbnis_nil(ft_rbnget_right(z)))
	{
		x = ft_rbnget_left(z);
		ft_rbttransplant(tree, z, x);
	}
	else
	{
		y = ft_rbnmin(ft_rbnget_right(z));
		original_color = y->color;
		x = replace_node(tree, z, y);
	}
	ft_rbndel(z, tree->del);
	if (original_color == RBT_BLACK)
		fixup(&tree->root, x);
	tree->size--;
}
