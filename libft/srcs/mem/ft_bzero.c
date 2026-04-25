/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:09 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:14:55 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

/**
 * @brief Sets the first n bytes of the block of memory pointed by s to zero.
 * 
 * @param s Pointer to the block of memory to fill with zero.
 * @param n Number of bytes to be set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		((unsigned char *)s)[n] = 0;
}
