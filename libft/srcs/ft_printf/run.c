/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:27:47 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 22:19:58 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/str.h"
#include "libft/is.h"
#include "libft/to.h"
#include "libft/mem.h"
#include "libft/math.h"
#include <stdlib.h>

static void	putch(t_data *data, char c)
{
	if (data->n < data->size)
	{
		if (data->str)
			data->str[data->n] = c;
		data->n++;
	}
}

static void	puthex(char *s, size_t n, char c, size_t len)
{
	while (len--)
	{
		if (n % 16 < 10)
			s[len] = (char)(n % 16 + '0');
		else
			s[len] = (char)(n % 16 - 10) + c;
		n /= 16;
	}
}

static size_t	nbrlen(size_t n, size_t base)
{
	if (n < base)
		return (1);
	return (1 + nbrlen(n / base, base));
}

static void	putunbr(char *s, size_t n, size_t len)
{
	while (len--)
	{
		s[len] = (char)(n % 10 + '0');
		n /= 10;
	}
}

static void	put_padding(t_data *data, size_t len)
{
	size_t	min;

	if (data->flags.width > len)
		min = data->flags.width - len;
	else
		min = 0;
	if (data->str)
	{
		if (data->flags.type & ZERO && !(data->flags.type & DOT))
			ft_memset(data->str + data->n, '0', min);
		else
			ft_memset(data->str + data->n, ' ', min);
	}
	data->n += min;
}

static void	puthex_flags(t_data *data, size_t n, char c)
{
	size_t	len;

	len = nbrlen(n, 16);
	if (data->flags.type & DOT && data->flags.precision == 0 && n == 0)
		len = 0;
	else if (data->flags.type & DOT && data->flags.precision > len)
		len = data->flags.precision;
	len = ft_zumin(len, data->size - data->n);
	if (!(data->flags.type & MINUS))
		put_padding(data, len);
	if (data->flags.type & HASH && n != 0)
	{
		putch(data, '0');
		putch(data, c);
	}
	if (data->str)
		puthex(data->str + data->n, n, c - ('x' - 'a'), len);
	data->n += len;
	if (data->flags.type & MINUS)
		put_padding(data, len);
}

static void	putunbr_flags(t_data *data, size_t n)
{
	size_t	len;

	len = nbrlen(n, 10);
	if (data->flags.type & DOT && data->flags.precision == 0 && n == 0)
		len = 0;
	else if (data->flags.type & DOT && data->flags.precision > len)
		len = data->flags.precision;
	len = ft_zumin(len, data->size - data->n);
	if (!(data->flags.type & MINUS))
		put_padding(data, len);
	if (data->str)
		putunbr(data->str + data->n, n, len);
	data->n += len;
	if (data->flags.type & MINUS)
		put_padding(data, len);
}

static void	putnbr_flags_padding(t_data *data, _Bool is_neg, size_t len)
{
	if (is_neg)
	{
		if (!(data->flags.type & ZERO && !(data->flags.type & DOT))
			&& !(data->flags.type & MINUS))
			put_padding(data, len + 1);
		putch(data, '-');
		if (data->flags.type & ZERO && !(data->flags.type & DOT))
			put_padding(data, len + 1);
	}
	else
	{
		if (!(data->flags.type & MINUS))
			put_padding(data, len);
		if (data->flags.type & PLUS)
			putch(data, '+');
		else if (data->flags.type & SPACE)
			putch(data, ' ');
	}
}

static void	putnbr_flags(t_data *data, ssize_t n)
{
	size_t	len;

	len = nbrlen(ft_zdabs(n), 10);
	if (data->flags.type & DOT && data->flags.precision == 0 && n == 0)
		len = 0;
	else if (data->flags.type & DOT && data->flags.precision > len)
		len = data->flags.precision;
	len = ft_zumin(len, data->size - data->n);
	putnbr_flags_padding(data, n < 0, len);
	if (data->str)
		putunbr(data->str + data->n, ft_zdabs(n), len);
	data->n += len;
	if (data->flags.type & MINUS)
		put_padding(data, len + (n < 0));
}

static void	putdouble_flags(t_data *data, double n, char type)
{
	// TODO
	(void)data;
	(void)n;
	(void)type;
}

static void	putstr_flags(t_data *data, char *s)
{
	size_t	len;

	if (!s && !(data->flags.type & DOT && data->flags.precision < 6))
		s = "(null)";
	len = ft_strlen(s);
	if (data->flags.type & DOT && data->flags.precision < len)
		len = data->flags.precision;
	len = ft_zumin(len, data->size - data->n);
	if (!(data->flags.type & MINUS))
		put_padding(data, len);
	if (data->str)
		ft_strlcpy(data->str + data->n, s, len + 1);
	data->n += len;
	if (data->flags.type & MINUS)
		put_padding(data, len);
}

static void	putptr_flags(t_data *data, void *ptr)
{
	size_t	len;

	if (!ptr)
		putstr_flags(data, "(nil)");
	else
	{
		len = ft_zumin(nbrlen((size_t)ptr, 16), data->size - data->n);
		if (!(data->flags.type & MINUS))
			put_padding(data, len + 2);
		if (data->str)
			ft_strlcpy(data->str + data->n, "0x", 3);
		data->n += 2;
		if (data->str)
			puthex(data->str + data->n, (size_t)ptr, 'a', len);
		data->n += len;
		if (data->flags.type & MINUS)
			put_padding(data, len + 2);
	}
}

static void	putchar_flags(t_data *data, char c)
{
	if (!(data->flags.type & MINUS))
		put_padding(data, 1);
	putch(data, c);
	if (data->flags.type & MINUS)
		put_padding(data, 1);
}

static void	handle_lengthl(t_data *data)
{
	data->fmt++;
	if (*data->fmt == 'd' || *data->fmt == 'i')
		putnbr_flags(data, va_arg(data->arg, long));
	else if (*data->fmt == 'u')
		putunbr_flags(data, va_arg(data->arg, unsigned long));
	else if (*data->fmt == 'x' || *data->fmt == 'X')
		puthex_flags(data, va_arg(data->arg, unsigned long), *data->fmt);
	else if (*data->fmt == 'l')
	{
		data->fmt++;
		if (*data->fmt == 'd' || *data->fmt == 'i')
			putnbr_flags(data, va_arg(data->arg, long long));
		else if (*data->fmt == 'u')
			putunbr_flags(data, va_arg(data->arg, unsigned long long));
		else if (*data->fmt == 'x' || *data->fmt == 'X')
			puthex_flags(data, va_arg(data->arg, unsigned long long),
				*data->fmt);
	}
}

static void	handle_length(t_data *data)
{
	if (*data->fmt == 'l')
		handle_lengthl(data);
	else if (*data->fmt == 'z')
	{
		data->fmt++;
		if (*data->fmt == 'd' || *data->fmt == 'i')
			putnbr_flags(data, va_arg(data->arg, ssize_t));
		else if (*data->fmt == 'u')
			putunbr_flags(data, va_arg(data->arg, size_t));
		else if (*data->fmt == 'x' || *data->fmt == 'X')
			puthex_flags(data, va_arg(data->arg, size_t), *data->fmt);
	}
}

static void	handle_type(t_data *data)
{
	if (*data->fmt == 'c')
		putchar_flags(data, (char)va_arg(data->arg, int));
	else if (*data->fmt == 's')
		putstr_flags(data, va_arg(data->arg, char *));
	else if (*data->fmt == 'd' || *data->fmt == 'i')
		putnbr_flags(data, va_arg(data->arg, int));
	else if (*data->fmt == 'u')
		putunbr_flags(data, va_arg(data->arg, unsigned int));
	else if (*data->fmt == 'x' || *data->fmt == 'X')
		puthex_flags(data, va_arg(data->arg, unsigned int), *data->fmt);
	else if (*data->fmt == 'f' || *data->fmt == 'F')
		putdouble_flags(data, va_arg(data->arg, double), *data->fmt);
	else if (*data->fmt == 'e' || *data->fmt == 'E')
		; // TODO: Notation scientifique (minuscule)
	else if (*data->fmt == 'g' || *data->fmt == 'G')
		; // TODO: Format court entre %f(F) et %e(E) (0.0001 à 999999 -> %f sinon %e)
	else if (*data->fmt == 'p')
		putptr_flags(data, va_arg(data->arg, void *));
	else if (*data->fmt == '%')
		putch(data, '%');
	else if (*data->fmt == 'n')
		*(va_arg(data->arg, int *)) = (int)data->n;
	else
		handle_length(data);
	data->fmt++;
}

static void	parse_flags(char *str, t_data *data)
{
	ft_bzero(&data->flags, sizeof(t_flags));
	while (*str)
	{
		if (*str == '-')
			data->flags.type |= MINUS;
		else if (*str == '0')
			data->flags.type |= ZERO;
		else if (*str == '.')
		{
			data->flags.type |= DOT;
			data->flags.precision = (size_t)ft_strtol(++str, &str, 10);
			continue ;
		}
		else if (*str == '#')
			data->flags.type |= HASH;
		else if (*str == ' ')
			data->flags.type |= SPACE;
		else if (*str == '+')
			data->flags.type |= PLUS;
		else if (ft_isdigit(*str))
		{
			data->flags.width = (size_t)ft_strtol(str, &str, 10);
			continue ;
		}
		else
			break ;
		str++;
	}
	data->fmt = str;
}

void	run(t_data *data)
{
	char	*tmp;
	size_t	min;

	while (*data->fmt && data->n < data->size)
	{
		tmp = ft_strchr(data->fmt, '%');
		if (!tmp)
		{
			if (data->str)
				ft_strlcpy(data->str + data->n, data->fmt,
					data->size - data->n + 1);
			data->n = ft_zumin(data->size, data->n + ft_strlen(data->fmt));
			break ;
		}
		min = ft_zumin(data->size - data->n, (size_t)(tmp - data->fmt));
		if (data->str)
			ft_strlcpy(data->str + data->n, data->fmt, min + 1);
		data->n += min;
		if (data->n >= data->size)
			break ;
		parse_flags(tmp + 1, data);
		handle_type(data);
	}
}
