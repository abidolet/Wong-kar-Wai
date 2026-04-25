/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidolet <abidolet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:55:53 by abidolet          #+#    #+#             */
/*   Updated: 2026/04/25 16:37:32 by abidolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIMITS_H
# define LIMITS_H

# define INT8_MIN -128
# define INT8_MAX 127
# define UINT8_MAX 255

# define CHAR_MIN INT8_MIN
# define CHAR_MAX INT8_MAX
# define UCHAR_MAX UINT8_MAX

# define INT16_MIN -32768
# define INT16_MAX 32767
# define UINT16_MAX 65535

# define SHRT_MIN INT16_MIN
# define SHRT_MAX INT16_MAX
# define USHRT_MAX UINT16_MAX

# define INT32_MIN -2147483648
# define INT32_MAX 2147483647
# define UINT32_MAX 4294967295U

# define INT_MIN INT32_MIN
# define INT_MAX INT32_MAX
# define UINT_MAX UINT32_MAX

# define INT64_MIN -9223372036854775808LL
# define INT64_MAX 9223372036854775807LL
# define UINT64_MAX 18446744073709551615ULL

# define LONG_MIN INT64_MIN
# define LONG_MAX INT64_MAX
# define ULONG_MAX UINT64_MAX

# define FLT_MIN 1.1754943508222875e-38F
# define FLT_MAX 3.4028234663852886e+38F
# define FLT_MAX_24 8.388608e+6F

# define DBL_MIN 2.2250738585072014e-308
# define DBL_MAX 1.7976931348623157e+308
# define DBL_MAX_53 4.503599627370496e+15

#endif
