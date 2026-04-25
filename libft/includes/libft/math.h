/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 23:51:25 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/17 00:54:53 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <sys/types.h>

unsigned char	ft_cabs(char n);
unsigned short	ft_sabs(short n);
unsigned int	ft_abs(int n);
unsigned long	ft_labs(long n);
size_t			ft_zdabs(ssize_t n);
float			ft_fabs(float n);
double			ft_dabs(double n);
char			ft_cclamp(char n, char min, char max);
unsigned char	ft_ucclamp(
					unsigned char n, unsigned char min, unsigned char max);
short			ft_sclamp(short n, short min, short max);
unsigned short	ft_usclamp(
					unsigned short n, unsigned short min, unsigned short max);
int				ft_clamp(int n, int min, int max);
unsigned int	ft_uclamp(unsigned int n, unsigned int min, unsigned int max);
long			ft_lclamp(long n, long min, long max);
unsigned long	ft_luclamp(
					unsigned long n, unsigned long min, unsigned long max);
size_t			ft_zuclamp(size_t n, size_t min, size_t max);
ssize_t			ft_zdclamp(ssize_t n, ssize_t min, ssize_t max);
float			ft_fclamp(float n, float min, float max);
double			ft_dclamp(double n, double min, double max);
char			ft_cmax(char a, char b);
unsigned char	ft_ucmax(unsigned char a, unsigned char b);
short			ft_smax(short a, short b);
unsigned short	ft_usmax(unsigned short a, unsigned short b);
int				ft_max(int a, int b);
unsigned int	ft_umax(unsigned int a, unsigned int b);
long			ft_lmax(long a, long b);
unsigned long	ft_lumax(unsigned long a, unsigned long b);
size_t			ft_zumax(size_t a, size_t b);
ssize_t			ft_zdmax(ssize_t a, ssize_t b);
float			ft_fmax(float a, float b);
double			ft_dmax(double a, double b);
char			ft_cmin(char a, char b);
unsigned char	ft_ucmin(unsigned char a, unsigned char b);
short			ft_smin(short a, short b);
unsigned short	ft_usmin(unsigned short a, unsigned short b);
int				ft_min(int a, int b);
unsigned int	ft_umin(unsigned int a, unsigned int b);
long			ft_lmin(long a, long b);
unsigned long	ft_lumin(unsigned long a, unsigned long b);
size_t			ft_zumin(size_t a, size_t b);
ssize_t			ft_zdmin(ssize_t a, ssize_t b);
float			ft_fmin(float a, float b);
double			ft_dmin(double a, double b);
double			ft_floor(double x);
double			ft_ceil(double x);
double			ft_round(double x);
double			ft_trunc(double x);
float			ft_floorf(float x);
float			ft_ceilf(float x);
float			ft_roundf(float x);
float			ft_truncf(float x);

# define ABS(x) _Generic((x), \
	char:		ft_cabs,	\
	short:		ft_sabs,	\
	int:		ft_abs,		\
	long:		ft_labs,	\
	float:		ft_fabs,	\
	double:		ft_dabs		\
)(x)

#define CLAMP(x, min, max) _Generic((x) + (min) + (max), \
	char:			ft_cclamp,	\
	unsigned char:	ft_ucclamp,	\
	short:			ft_sclamp,	\
	unsigned short:	ft_usclamp,	\
	int:			ft_clamp,	\
	unsigned int:	ft_uclamp,	\
	long:			ft_lclamp,	\
	unsigned long:	ft_luclamp,	\
	float:			ft_fclamp,	\
	double:			ft_dclamp	\
)(x, min, max)

#define MAX(a, b) _Generic((a) + (b), \
	char:			ft_cmax,	\
	unsigned char:	ft_ucmax,	\
	short:			ft_smax,	\
	unsigned short:	ft_usmax,	\
	int:			ft_max,		\
	unsigned int:	ft_umax,	\
	long:			ft_lmax,	\
	unsigned long:	ft_lumax,	\
	float:			ft_fmax,	\
	double:			ft_dmax		\
)(a, b)

#define MIN(a, b) _Generic((a) + (b), \
	char:			ft_cmin,	\
	unsigned char:	ft_ucmin,	\
	short:			ft_smin,	\
	unsigned short:	ft_usmin,	\
	int:			ft_min,		\
	unsigned int:	ft_umin,	\
	long:			ft_lmin,	\
	unsigned long:	ft_lumin,	\
	float:			ft_fmin,	\
	double:			ft_dmin		\
)(a, b)

#endif
