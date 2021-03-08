/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_part.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 22:28:53 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/08 00:33:22 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>

static int	print_until_next_conv(char *format)
{
	size_t	len;

	len = 0;
	while (format[len] != '\0' && format[len] != '%')
		len++;
	return (write(1, format, len));
}

static int	print_conversion(t_conv *conv, int cur_len, va_list ap)
{
	(void)cur_len;
	if (conv->e_type == CHAR)
		return (print_c(conv, va_arg(ap, int)));
	if (conv->e_type == STRING)
		return (print_s(conv, va_arg(ap, char *)));
	return (0);
}

char	*print_part(char *format, va_list ap, int *len, t_conv *tmp_conv_arg)
{
	t_conv	conv;
	char	*after_part;
	int		part_len;

	if (format[0] == '%')
	{
		format++;
		after_part = parse_conversion(format, &conv, ap);
		*tmp_conv_arg = conv;
		part_len = print_conversion(&conv, *len, ap);
		if (part_len < 0)
			return (NULL);
		*len += part_len;
		return (after_part);
	}
	part_len = print_until_next_conv(format);
	if (part_len < 0)
		return (NULL);
	*len += part_len;
	return (format + part_len);
}
