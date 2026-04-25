/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:34:53 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:27:11 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/is.h"

/**
 * @brief Checks if a character is a hexadecimal digit.
 * 
 * @param c The character to check.
 * @return true if the character is a hexadecimal digit, false otherwise.
 */
bool	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'));
}
