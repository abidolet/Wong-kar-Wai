/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 00:35:15 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/25 10:57:11 by abidolet         ###   ########.fr       */
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
	const char	*tags[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"};
	const int	fds[5] = {2, 2, 2, 2, 2};

	if (log.level < DEBUG_LEVEL || log.level < LOG_LEVEL
		|| log.level > FATAL_LEVEL)
		return ;
	ft_dprintf(fds[log.level - 1], "[%s] ", tags[log.level - 1]);
	va_start(ap, format);
	ft_vdprintf(fds[log.level - 1], format, ap);
	va_end(ap);
	ft_dprintf(fds[log.level - 1], " in %s (%s:%d)\n",
		log.func, log.file, log.line);
}
