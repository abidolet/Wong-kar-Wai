/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:02:34 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 16:43:56 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_H
# define IS_H

# include <stdbool.h>

bool	ft_isalnum(int c);
bool	ft_isalpha(int c);
bool	ft_isascii(int c);
bool	ft_isblank(int c);
bool	ft_iscntrl(int c);
bool	ft_isdigit(int c);
bool	ft_isgraph(int c);
bool	ft_islower(int c);
bool	ft_isprint(int c);
bool	ft_ispunct(int c);
bool	ft_isspace(char c);
bool	ft_isupper(int c);
bool	ft_isxdigit(int c);

#endif
