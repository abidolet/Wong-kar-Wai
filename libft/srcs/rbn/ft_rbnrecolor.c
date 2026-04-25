/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnrecolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:43:35 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:07 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
/**
 * @brief Toggle the color of a node
 * 
 * @param rbn The node to recolor
 * @return void
 */
void	ft_rbnrecolor(t_rbn *rbn)
{
	rbn->color = !rbn->color;
}
