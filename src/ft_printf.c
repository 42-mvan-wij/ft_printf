/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 13:25:10 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/27 14:11:16 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
// #include "../lib/libft/libft.h"
#include <unistd.h>

int	printf(const char *format_string, ...)
{
	va_list	ap;
	char	*format;

	va_start(ap, format_string);
	format = (char *)format_string;
	while (*format != '\0')
	{
		write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (0);
}
