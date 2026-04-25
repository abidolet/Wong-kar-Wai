/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnattach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:29:35 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:06:00 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Attaches a child node to a parent node on the specified side.
 * 
 * @param parent	Pointer to the parent red-black tree node.
 * @param child		Pointer to the child red-black tree node.
 * @param side		The side to append the child.
 */
void	ft_rbnattach(t_rbn *parent, t_rbn *child, t_side side)
{
	if (!ft_rbnis_nil(parent))
	{
		if (side == LEFT)
			ft_rbnset_left(parent, child);
		else
			ft_rbnset_right(parent, child);
	}
}
