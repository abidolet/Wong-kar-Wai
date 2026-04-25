/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:41:40 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 18:01:18 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/to.h"
#include "libft/is.h"

long	ft_atol(const char *nptr)
{
	long long	res;
	int			sign;

	if (!nptr)
		return (-1);
	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + *nptr++ - '0';
		if (res * sign != (long)(res * sign))
			return (-1);
	}
	return ((long)(res * sign));
}
