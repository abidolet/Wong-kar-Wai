/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:41:19 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 18:02:03 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/to.h"
#include "libft/is.h"
#include "limits.h"

int	ft_strtoi(const char *nptr, char **endptr, int base)
{
	const int	max = INT_MAX / base;
	const int	min = -INT_MAX - 1 / base;
	int			res;
	char		sign;

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
	{
		if (res * sign > max + **endptr - '0'
			|| res * sign < min + **endptr - '0')
			return (-1);
		res = res * base + *(*endptr)++ - '0';
	}
	return (res * sign);
}
