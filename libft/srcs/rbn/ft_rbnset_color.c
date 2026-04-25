/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnset_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:43:35 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 11:51:02 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
/**
 * @brief Set the color of a node
 * 
 * @param rbn	The node to colored
 * @param color	The color to set
 * @return void
 */
void	ft_rbnset_color(t_rbn *rbn, t_rbtcolor color)
{
	rbn->color = color;
}
