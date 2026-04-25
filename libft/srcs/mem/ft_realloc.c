/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:06:52 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 19:37:50 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include <stdlib.h>

/**
 * @brief Changes the size of the memory block pointed to by ptr to size bytes.
 * 
 * @param ptr	Pointer to a memory block previously allocated.
 * @param size	New size for the memory block, in bytes.
 * @return void* A pointer to the reallocated memory.
 * @note If ptr is NULL, the function behaves like malloc(size).
 * @note If size is zero the function behaves like free(ptr) and returns NULL.
 */
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*res;

	if (!ptr)
		return (malloc(new_size));
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(new_size);
	if (!res)
		return (NULL);
	ft_memcpy(res, ptr, old_size);
	free(ptr);
	return (res);
}
