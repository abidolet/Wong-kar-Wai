/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnget_uncle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:35:43 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:52 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Retrieves the uncle of a red-black tree node.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return Pointer to the uncle node.
 */
t_rbn	*ft_rbnget_uncle(t_rbn *rbn)
{
	return (ft_rbnget_sibling(ft_rbnget_parent(rbn)));
}
