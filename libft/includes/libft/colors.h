/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:19:57 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/15 16:10:10 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# ifndef PRETTY
#  define PRETTY 1
# endif

# if PRETTY

#  define RED "\033[31m"
#  define GREEN "\033[32m"
#  define YELLOW "\033[33m"
#  define BLUE "\033[34m"
#  define MAGENTA "\033[35m"
#  define CYAN "\033[36m"
#  define GRAY "\033[90m"
#  define RESET "\033[0m"
#  define BOLD "\033[1m"
#  define BOLD_RED "\033[1m\033[31m"
#  define UNDERLINE "\033[4m"

# else

#  define RED ""
#  define GREEN ""
#  define YELLOW ""
#  define BLUE ""
#  define MAGENTA ""
#  define CYAN ""
#  define GRAY ""
#  define RESET ""
#  define BOLD ""
#  define BOLD_RED ""
#  define UNDERLINE ""

# endif

#endif
