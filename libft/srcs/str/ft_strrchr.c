/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:51:52 by abidolet          #+#    #+#             */
/*   Updated: 2025/02/15 21:51:52 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	if (!s)
		return (NULL);
	res = NULL;
	while (*s)
	{
		if (*s == (char)c)
			res = (char *)s;
		s++;
	}
	if (s && *s == (char)c)
		return ((char *)s);
	return (res);
}
