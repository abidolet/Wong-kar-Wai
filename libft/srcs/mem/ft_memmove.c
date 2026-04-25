/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:00:06 by abidolet          #+#    #+#             */
/*   Updated: 2024/11/22 00:00:06 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

/**
 * @brief Copy memory area. The memory areas may overlap.
 * 
 * @param dest	Pointer to the destination array.
 * @param src	Pointer to the source of data to be copied.
 * @param n		Number of bytes to copy.
 * @return void* A pointer to the destination area dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;
	void			*res;

	src_ptr = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	res = dest;
	dest_ptr = (unsigned char *)dest;
	if (dest < src || (unsigned char *)dest >= (unsigned char *)src + n)
		while (n--)
			*dest_ptr++ = *src_ptr++;
	else
		while (n--)
			*(dest_ptr + n) = *(src_ptr + n);
	return (res);
}
