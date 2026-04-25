/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:06:46 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 17:32:25 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/print.h"

enum e_flags_type
{
	MINUS = 1 << __COUNTER__,
	ZERO = 1 << __COUNTER__,
	DOT = 1 << __COUNTER__,
	HASH = 1 << __COUNTER__,
	SPACE = 1 << __COUNTER__,
	PLUS = 1 << __COUNTER__,
};

typedef struct flags
{
	char	type;
	size_t	width;
	size_t	precision;
}	t_flags;

typedef struct data
{
	char	*str;
	char	*fmt;
	t_flags	flags;
	size_t	size;
	size_t	n;
	va_list	arg;
}	t_data;

void	run(t_data *data);

#endif
