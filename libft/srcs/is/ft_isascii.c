/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:17:02 by abidolet          #+#    #+#             */
/*   Updated: 2025/01/13 23:53:25 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/is.h"

/**
 * @brief Checks if a character is a 7-bit ASCII character.
 * 
 * @param c The character to check.
 * @return true if the character is in the ASCII character set, false otherwise.
 */
bool	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
