/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 22:44:13 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/22 13:54:06 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

char	*precision_digits(int precision, char *str)
{
	uint8_t	len;
	bool	has_sign;
	char	*dst;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (precision == 0 && len == 1 && *str == '0')
		return (ft_memdup("", 1));
	has_sign = str[0] == '-' || str[0] == '+';
	len -= has_sign;
	if (precision < 0 || precision <= len)
		return (ft_memdup(str, len + has_sign + 1));
	dst = malloc(precision + has_sign + 1);
	if (dst == NULL)
		return (NULL);
	// ft_memset(dst, '*', precision + has_sign);
	dst[0] = str[0];
	ft_memset(dst + has_sign, '0', precision - len);
	ft_memmove(dst + has_sign + precision - len, str + has_sign, len + 1);
	return (dst);
}

char	*precision_chars(int precision, char *str)
{
	size_t	len;
	char	*dst;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (precision < 0 || precision >= len)
		return (ft_memdup(str, len + 1));
	dst = ft_memdup(str, precision + 1);
	if (dst == NULL)
		return (NULL);
	dst[precision] = '\0';
	return (dst);
}

// char	*precision_radix(int precision, char *str); // ?
