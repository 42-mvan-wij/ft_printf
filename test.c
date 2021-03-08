/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 14:37:48 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/08 00:33:42 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// #define TEST(...) __VA_ARGS__
#define FT_PRINTF(format,...){write(1,"\"",1);ft_printf(format,print_info __VA_OPT__(,) __VA_ARGS__);}

char	*pad_name(t_conv *conv)
{
	if (conv->e_pad_type == LEFT)
		return ("LEFT");
	if (conv->e_pad_type == RIGHT)
		return ("RIGHT");
	if (conv->e_pad_type == ZERO)
		return ("ZERO");
	return ("(UNKNOWN)");
}

char	*type_name(t_conv *conv)
{
	if (conv->e_type == UNSET)
		return ("UNSET");
	if (conv->e_type == CHAR)
		return ("CHAR");
	if (conv->e_type == STRING)
		return ("STRING");
	if (conv->e_type == INT)
		return ("INT");
	if (conv->e_type == UINT)
		return ("UINT");
	if (conv->e_type == HEX_LOW)
		return ("HEX_LOW");
	if (conv->e_type == HEX_CAP)
		return ("HEX_CAP");
	if (conv->e_type == PTR)
		return ("PTR");
	return ("(UNKNOWN)");
}

void	print_info(int len, t_conv *conv)
{
	printf("\
\" (%i)\n\
fw: %i,\n\
p: %i,\n\
pad: %s,\n\
type: %s\n\n",
	len, conv->field_width, conv->precision, pad_name(conv),
	type_name(conv));
	fflush(NULL);
}

int	main(void)
{
	FT_PRINTF("test");
	FT_PRINTF("hello %-13s", "world");
	FT_PRINTF("char: %c", 'c');
	FT_PRINTF("char: %c", '\0');
	FT_PRINTF("%*.c", -32, 'a');
	return (0);
}
