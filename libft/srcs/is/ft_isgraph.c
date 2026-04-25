/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:28:31 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:31:39 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/is.h"

/**
 * @brief Checks if a character has a graphical representation.
 * 
 * @param c The character to check.
 * @return true if the character is printable and not a space, false otherwise.
 */
bool	ft_isgraph(int c)
{
	return (c >= 33 && c <= 126);
}
