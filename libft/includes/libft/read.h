/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:16:59 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 19:21:29 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <sys/types.h>
# include <stdbool.h>
#include "libft/vec.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_MAX 1024

bool		ft_checkextension(const char *filename, const char *extension);
ssize_t		ft_getdelim(char **lineptr, size_t *n, int delim, int fd);
ssize_t		ft_getline(char **lineptr, size_t *n, int fd);
ssize_t		ft_getfile(char **fileptr, size_t *n, int fd);
t_vector	*ft_readfile(int fd);
char		*get_next_line(int fd);

#endif
