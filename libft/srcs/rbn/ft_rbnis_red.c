/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnis_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:47:38 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 11:51:25 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Checks if a red-black tree node is red.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return True if red, otherwise false.
 */
bool	ft_rbnis_red(t_rbn *rbn)
{
	return (rbn->color == RBT_RED);
}
