/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbnset_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:43:35 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 10:32:27 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/rbn.h"
/**
 * @brief Set the data of a node
 * 
 * @param rbn	The node to set data for
 * @param data	The data to set
 * @return void
 */
void	ft_rbnset_data(t_rbn *rbn, void *data)
{
	rbn->data = data;
}
