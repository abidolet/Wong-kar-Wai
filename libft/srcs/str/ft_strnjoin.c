/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:35:20 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 00:36:34 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"
#include "libft/math.h"
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return (ft_strndup(s2, n));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_zumin(ft_strlen(s2), n);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcpy(res + len1, s2, len2 + 1);
	return (res);
}
