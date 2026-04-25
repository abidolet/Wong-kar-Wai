/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:29:40 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:32:09 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/is.h"

/**
 * @brief Checks if a character is a punctuation character.
 * 
 * @param c The character to check.
 * @return true if the character is a punctuation character, false otherwise.
 */
bool	ft_ispunct(int c)
{
	return ((c >= 33 && c <= 47) || (c >= 58 && c <= 64)
		|| (c >= 91 && c <= 96) || (c >= 123 && c <= 126));
}
