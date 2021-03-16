/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_conv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 22:18:03 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/16 15:56:28 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../lib/libft/libft.h"
#include <stdarg.h>
#include <stddef.h>

static char	*parse_flags(char *format, t_conv *conv)
{
	set_default_flags(conv);
	while (*format != '\0')
	{
		if (*format == '0')
		{
			if (conv->e_pad_type != RIGHT)
				conv->e_pad_type = ZERO;
		}
		else if (*format == '-')
			conv->e_pad_type = RIGHT;
		else
			return (format);
		format++;
	}
	return (format);
}

static char	*parse_field_width(char *format, t_conv *conv, va_list ap)
{
	if (format[0] == '*')
	{
		conv->field_width = va_arg(ap, int);
		if (conv->field_width < 0)
		{
			conv->field_width = -conv->field_width;
			conv->e_pad_type = RIGHT;
		}
		return (format + 1);
	}
	if (!ft_isdigit(format[0]))
		return (format);
	conv->field_width = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static char	*parse_precision(char *format, t_conv *conv, va_list ap)
{
	if (format[0] != '.')
		return (format);
	format++;
	if (format[0] == '*')
	{
		conv->precision = va_arg(ap, int);
		return (format + 1);
	}
	conv->precision = ft_atoi(format);
	if (*format == '-' || *format == '+')
		format++;
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static void	parse_conv_type(char *format, t_conv *conv)
{
	if (format[0] == '%')
		conv->e_type = PCT;
	else if (format[0] == 'c')
		conv->e_type = CHAR;
	else if (format[0] == 's')
		conv->e_type = STRING;
	else if (format[0] == 'i' || format[0] == 'd')
		conv->e_type = INT;
	else if (format[0] == 'u')
		conv->e_type = UINT;
	//else if (format[0] == 'f')
		//conv->type = FLOAT;
	else if (format[0] == 'x')
		conv->e_type = HEX_LOW;
	else if (format[0] == 'X')
		conv->e_type = HEX_CAP;
	else if (format[0] == 'p')
		conv->e_type = PTR;
	else if (format[0] == 'n')
		conv->e_type = NBR;
	else
		conv->e_type = UNSET;
}

char	*parse_conversion(char *format, t_conv *conv, va_list ap)
{
	if (format == NULL)
		return (NULL);
	// flags
	format = parse_flags(format, conv);
	// min field width
	format = parse_field_width(format, conv, ap);
	// precision
	format = parse_precision(format, conv, ap);
	// if (conv->precision >= 0 && conv->e_pad_type == ZERO)
	// 	conv->e_pad_type = LEFT;
	// length modifier (probaly not worth)
	//
	// conversion type
	parse_conv_type(format, conv);
	return (format + 1);
}
