/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:32:37 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/23 18:03:08 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include <stddef.h>
# include <sys/types.h>

typedef struct s_algo
{
	void	*base;
	size_t	n;
	size_t	size;
	int		(*cmp)(const void *, const void *);
}	t_algo;

void	ft_qsort(t_algo algo);
void	ft_swap(void *a, void *b, size_t size);
ssize_t	ft_binary_search(t_algo algo, const void *key);
ssize_t	ft_linear_search(t_algo algo, const void *key);
void	ft_reverse(t_algo algo, size_t begin, size_t end);
void	ft_rotate(t_algo algo, size_t k, int side);
ssize_t	ft_unique(t_algo algo);

#endif
