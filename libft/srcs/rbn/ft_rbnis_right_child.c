/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnis_right_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:49:39 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:52 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Checks if a red-black tree node is a right child.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return True if it is a right child, otherwise false.
 */
bool	ft_rbnis_right_child(t_rbn *rbn)
{
	return (ft_rbnget_right(ft_rbnget_parent(rbn)) == rbn);
}
