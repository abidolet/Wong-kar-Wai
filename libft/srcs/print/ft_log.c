/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 00:35:15 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:02:09 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/print.h"

/**
 * @brief Print a formatted log message
 * 
 * @param log		Log configuration structure
 * @param format	Format string
 */
void	ft_log(t_log log, const char *format, ...)
{
	va_list		ap;
	const char	*colors[5] = {BLUE, GREEN, YELLOW, RED, BOLD_RED};
	const char	*tags[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"};
	const int	fds[5] = {1, 1, 1, 2, 2};

	if (log.level < DEBUG_LEVEL || log.level < LOG_LEVEL
		|| log.level > FATAL_LEVEL)
		return ;
	ft_dprintf(fds[log.level - 1], "%s[%s]%s ",
		colors[log.level - 1], tags[log.level - 1], RESET);
	va_start(ap, format);
	ft_vdprintf(fds[log.level - 1], format, ap);
	va_end(ap);
	ft_dprintf(fds[log.level - 1], " in %s%s%s (%s%s:%d%s)\n",
		MAGENTA, log.func, RESET, GRAY, log.file, log.line, RESET);
}
