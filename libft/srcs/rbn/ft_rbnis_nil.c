/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnis_nil.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:36:54 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/18 16:06:29 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"

/**
 * @brief Checks if a red-black tree node is the nil sentinel node.
 * 
 * @param rbn Pointer to the red-black tree node.
 * @return True if nil, otherwise false.
 * @note The nil sentinel replace NULL in a red-black tree.
 */
bool	ft_rbnis_nil(t_rbn *rbn)
{
	return (rbn == ft_rbnget_left(rbn));
}
