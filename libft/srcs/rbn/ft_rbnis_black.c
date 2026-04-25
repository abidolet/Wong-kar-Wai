/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnis_black.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:47:38 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 11:51:35 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Checks if a red-black tree node is black.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return True if black, otherwise false.
 */
bool	ft_rbnis_black(t_rbn *rbn)
{
	return (rbn->color == RBT_BLACK);
}
