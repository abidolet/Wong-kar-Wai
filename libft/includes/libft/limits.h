/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:55:53 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/16 00:05:12 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIMITS_H
# define LIMITS_H

# define CHAR_MIN -128
# define CHAR_MAX 127
# define UCHAR_MAX 255

# define SHRT_MIN -32768
# define SHRT_MAX 32767
# define USHRT_MAX 65535

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define UINT_MAX 4294967295U

# define LONG_MIN -9223372036854775808L
# define LONG_MAX 9223372036854775807L
# define ULONG_MAX 18446744073709551615UL

# define FLT_MIN 1.1754943508222875e-38F
# define FLT_MAX 3.4028234663852886e+38F
# define FLT_MAX_24 8.388608e+6F

# define DBL_MIN 2.2250738585072014e-308
# define DBL_MAX 1.7976931348623157e+308
# define DBL_MAX_53 4.503599627370496e+15

#endif
