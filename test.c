/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 14:37:48 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/15 17:29:05 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// #define TEST(...) __VA_ARGS__
#define FT_PRINTF_SINGLE(format, ...) {\
	write(1, "\"", 1);\
	printf("\" (%i) <== expected\n\"", printf(format));\
	fflush(NULL);\
	ft_printf(format, print_info);\
}

#define FT_PRINTF(format, ...) {\
	write(1, "\"", 1);\
	printf("\" (%i) <== expected\n\"",  printf(format, __VA_ARGS__));\
	fflush(NULL);\
	ft_printf(format, __VA_ARGS__, print_info);\
}

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
	if (conv->e_type == PCT)
		return ("PCT");
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
	(void)len;
	(void)conv;
	printf("\" (%i) <== got\n\n", len);
	/*printf("\
\" (%i) <== got\n\
fw: %i,\n\
p: %i,\n\
pad: %s,\n\
type: %s\n\n",
	len, conv->field_width, conv->precision, pad_name(conv),
	type_name(conv));*/
	fflush(NULL);
}

#include "lib/libft/libft.h"
#include <stdlib.h>
int	main(void)
{
	FT_PRINTF("%05s", "h");
	FT_PRINTF_SINGLE("%-05%");
	FT_PRINTF_SINGLE("hello, world!");
	FT_PRINTF("hello %-13s", "world");
	FT_PRINTF("hello %.2s", "world");
	FT_PRINTF("hello %.3s", NULL);
	FT_PRINTF("char: %c", 'c');
	FT_PRINTF("char: %c", '\0');
	FT_PRINTF("%c", 'a');
	FT_PRINTF("%i", -__INT_MAX__-1);
	FT_PRINTF("%.37i", -__INT_MAX__-1);
	FT_PRINTF("%X", __UINT32_MAX__);
	FT_PRINTF("%u", __UINT32_MAX__);
	FT_PRINTF("%p", (void *)__UINT64_MAX__);
	return (0);
}
