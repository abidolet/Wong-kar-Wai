/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:04:23 by abidolet          #+#    #+#             */
/*   Updated: 2025/05/31 20:32:30 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/is.h"

/**
 * @brief Checks if a character is a space character.
 * 
 * @param c The character to check.
 * @return true if the character is a space character, false otherwise.
 */
bool	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
