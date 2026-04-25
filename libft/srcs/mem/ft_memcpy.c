/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:18:55 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:55:59 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

/**
 * @brief Copy memory area.
 * 
 * @param dest	Pointer to the destination array.
 * @param src	Pointer to the source of data to be copied.
 * @param n		Number of bytes to copy.
 * @return void* A pointer to the destination area dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (dest);
	while (n-- > 0)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
