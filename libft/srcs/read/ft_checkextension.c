/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkextension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:54:49 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 13:02:25 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/read.h"
#include "libft/str.h"

/**
 * @brief Checks if the filename has the specified extension.
 * 
 * @param filename	Name of the file to check.
 * @param extension	Extension to compare with the file's extension.
 * @return true if the filename has the specified extension, false otherwise. 
 */
bool	ft_checkextension(const char *filename, const char *extension)
{
	const char	*filename_extension = ft_strrchr(filename, '.');

	if (!extension || !filename_extension)
		return (false);
	return (ft_strcmp(filename_extension, extension) == 0);
}
