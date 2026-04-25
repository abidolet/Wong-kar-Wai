/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:53:04 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 17:57:38 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	res;

	if (!str || !*str)
		return (0);
	res = 0;
	while (str[res])
		res++;
	return (res);
}
