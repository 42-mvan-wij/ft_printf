/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 13:25:10 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/22 12:24:16 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "ft_printf.h"

int	ft_printf(const char *format_string, ...)
{
	va_list	ap;
	char	*format;
	int		len;
	t_conv	tmp_conv_arg; // tmp

	va_start(ap, format_string);
	format = (char *)format_string;
	len = 0;
	set_default_flags(&tmp_conv_arg); // tmp
	while (format[0] != '\0')
	{
		format = print_part(format, ap, &len, &tmp_conv_arg); // ~tmp
		if (format == NULL)
			return (-1);
	}
	#ifdef WITH_FN
	void (*fn)(int, t_conv *) = va_arg(ap, void *); // tmp
	fn(len, &tmp_conv_arg); // tmp
	#endif
	va_end(ap);
	return (len);
}
