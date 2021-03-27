/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 13:25:10 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/27 13:06:32 by mvan-wij      ########   odam.nl         */
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

	va_start(ap, format_string);
	format = (char *)format_string;
	len = 0;
	while (format[0] != '\0')
	{
		format = print_part(format, ap, &len);
		if (format == NULL)
			return (-1);
	}
	va_end(ap);
	return (len);
}
