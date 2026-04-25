/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:41:13 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 18:02:15 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/to.h"
#include "libft/is.h"
#include "libft/limits.h"
#include <stdio.h>

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long	res;
	char	sign;

	if (!nptr || !endptr || base < 2 || base > 36)
		return (-1);
	*endptr = (char *)nptr;
	res = 0;
	sign = 1;
	while (ft_isspace(**endptr))
		(*endptr)++;
	if (**endptr == '-' || **endptr == '+')
		if (*(*endptr)++ == '-')
			sign = -1;
	while (ft_isdigit(**endptr))
		res = res * base + *(*endptr)++ - '0';
	return (res * sign);
}
