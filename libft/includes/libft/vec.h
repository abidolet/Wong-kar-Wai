/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:30:00 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/24 13:55:05 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <stddef.h>
# include <sys/types.h>
# include <stdbool.h>

typedef struct s_vector
{
	void	*data;
	size_t	elt_size;
	size_t	size;
	size_t	capacity;
	void	(*del)(void *);
}	t_vector;

void		ft_vecassign(t_vector *dest, t_vector *src);
void		*ft_vecat(t_vector *vec, size_t index);
void		*ft_vecback(t_vector *vec);
void		ft_vecclear(t_vector *vec);
t_vector	*ft_vecclone(t_vector *vec);
bool		ft_vecempty(t_vector *vec);
void		*ft_vecend(t_vector *vec);
void		ft_vecerase(t_vector *vec, size_t index);
ssize_t		ft_vecfind_sorted(t_vector *vec, const void *key,
				int (*cmp)(const void *, const void *));
ssize_t		ft_vecfind(t_vector *vec, const void *key,
				int (*cmp)(const void *, const void *));
void		*ft_vecfront(t_vector *vec);
void		ft_vecinit(t_vector *vec, size_t elt_size, void (*del)(void *));
bool		ft_vecinsert(t_vector *vec, size_t index, void *element);
void		ft_veciter(t_vector *vec, void (*f)(void *));
t_vector	*ft_vecmap(t_vector *vec, void *(*f)(void *));
t_vector	*ft_vecmerge(t_vector *a, t_vector *b);
t_vector	*ft_vecnew(size_t elt_size, void (*del)(void *));
void		ft_vecpop_back(t_vector *vec);
bool		ft_vecpush_back(t_vector *vec, void *element);
void		ft_vecremove_if(t_vector *vec, int (*cmp)(void *));
bool		ft_vecreserve(t_vector *vec, size_t new_capacity);
bool		ft_vecresize(t_vector *vec, size_t new_size);
void		ft_vecreverse(t_vector *vec);
void		ft_vecrotate(t_vector *vec, size_t k, int direction);
bool		ft_vecshrink_to_fit(t_vector *vec);
size_t		ft_vecsize(t_vector *vec);
void		ft_vecsort(t_vector *vec, int (*cmp)(const void *, const void *));
void		ft_vecunique(t_vector *vec, int (*cmp)(const void *, const void *));

#endif
