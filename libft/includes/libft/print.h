/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:23:44 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/17 00:13:15 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <sys/types.h>
# include "libft/colors.h"

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(long n, int fd);

int		ft_printf(const char *format, ...)
		__attribute__((format (printf, 1, 2)));
int		ft_dprintf(int fd, const char *format, ...)
		__attribute__((format (printf, 2, 3)));
int		ft_asprintf(char **strp, const char *format, ...)
		__attribute__((format (printf, 2, 3)));
int		ft_sprintf(char *str, const char *format, ...)
		__attribute__((format (printf, 2, 3)));
int		ft_snprintf(char *str, size_t size, const char *format, ...)
		__attribute__((format (printf, 3, 4)));

int		ft_vprintf(const char *str, va_list ap);
int		ft_vdprintf(int fd, const char *str, va_list ap);
int		ft_vasprintf(char **strp, const char *format, va_list ap);
int		ft_vsprintf(char *str, const char *format, va_list ap);
int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);

typedef enum e_log_level
{
	NONE = 0,
	DEBUG_LEVEL = 1,
	INFO_LEVEL = 2,
	WARNING_LEVEL = 3,
	ERROR_LEVEL = 4,
	FATAL_LEVEL = 5
}	t_log_level;

typedef struct s_log
{
	t_log_level	level;
	int			line;
	const char	*func;
	const char	*file;
}	t_log;

# ifndef LOG_LEVEL
#  define LOG_LEVEL (t_log_level)2
# endif

void	ft_log(t_log log, const char *format, ...)
		__attribute__((format(printf, 2, 3)));

# define LOG_INIT(level)	(t_log){level, __LINE__, __func__, __FILE__}
# define LOG(level, ...)	ft_log(LOG_INIT(level), __VA_ARGS__)
# define DEBUG(...)			LOG(DEBUG_LEVEL, __VA_ARGS__)
# define INFO(...)			LOG(INFO_LEVEL, __VA_ARGS__)
# define WARNING(...)		LOG(WARNING_LEVEL, __VA_ARGS__)
# define ERROR(...)			LOG(ERROR_LEVEL, __VA_ARGS__)
# define FATAL(...)			LOG(FATAL_LEVEL, __VA_ARGS__)

#endif
