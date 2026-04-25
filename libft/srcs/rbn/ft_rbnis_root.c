/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnis_root.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:07:34 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/18 16:02:39 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Checks if a red-black tree node is the root.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return True if it is the root, otherwise false.
 */
bool	ft_rbnis_root(t_rbn *rbn)
{
	return (ft_rbnis_nil(ft_rbnget_parent(rbn)));
}
