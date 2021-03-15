/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_part.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 22:28:53 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/15 16:23:18 by mvan-wij      ########   odam.nl         */
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
	if (conv->e_type == PCT)
		return (print_pct(conv));
	if (conv->e_type == CHAR)
		return (print_c(conv, va_arg(ap, int)));
	if (conv->e_type == STRING)
		return (print_s(conv, va_arg(ap, char *)));
	if (conv->e_type == INT)
		return (print_i(conv, va_arg(ap, int)));
	if (conv->e_type == UINT)
		return (print_u(conv, va_arg(ap, int)));
	if (conv->e_type == HEX_LOW || conv->e_type == HEX_CAP)
		return (print_x(conv, va_arg(ap, unsigned), conv->e_type == HEX_CAP));
	if (conv->e_type == PTR)
		return (print_p(conv, va_arg(ap, void *)));
	return (-1);
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
