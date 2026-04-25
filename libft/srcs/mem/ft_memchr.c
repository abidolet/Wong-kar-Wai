/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:18:41 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 09:53:16 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

/**
 * @brief Scan memory for a character.
 * 
 * @param s Pointer to the block of memory where the search is performed.
 * @param c Value to be located.
 * @param n Number of bytes to be analyzed.
 * @return void* The matching byte or NULL if the character is not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
