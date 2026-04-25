/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:16:55 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 08:40:03 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/is.h"

/**
 * @brief Checks if a character is alphabetic.
 * 
 * @param c The character to check.
 * @return true if the character is alphabetic, false otherwise.
 */
bool	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
