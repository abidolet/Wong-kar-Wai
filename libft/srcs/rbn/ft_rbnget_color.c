/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnget_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:05:56 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 11:51:02 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Retrieves the color of a red-black tree node.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return The color of the node.
 */
t_rbtcolor	ft_rbnget_color(t_rbn *rbn)
{
	return (rbn->color);
}
