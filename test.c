/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 14:37:48 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/17 14:16:22 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include "lib/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>
// #define SKIP_REG

#define PRINTF_SINGLE(format) {\
	printf("ft_printf(%s):\n\"", format);\
	printf("\" (%i) <== expected\n", printf(format));\
	fflush(NULL);\
}

#define PRINTF(format, ...) {\
	printf("ft_printf(%s, %s):\n\"", format, #__VA_ARGS__);\
	printf("\" (%i) <== expected\n", printf(format, __VA_ARGS__));\
	fflush(NULL);\
}

// #define TEST(...) __VA_ARGS__
#define FT_PRINTF_SINGLE(format) {\
	PRINTF_SINGLE(format);\
	write(1, "\"", 1);\
	ft_printf(format, print_info);\
}

#define FT_PRINTF(format, ...) {\
	PRINTF(format, __VA_ARGS__);\
	write(1, "\"", 1);\
	ft_printf(format, __VA_ARGS__, print_info);\
}

#define PRINTF_SINGLE_NL(format) {\
	PRINTF_SINGLE(format);\
	write(1, "\n", 1);\
}

#define PRINTF_NL(format, ...) {\
	PRINTF(format, __VA_ARGS__);\
	write(1, "\n", 1);\
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

int	main(void)
{
	#ifndef SKIP_REG
	// regular tests
	FT_PRINTF("%c", 'a');
	FT_PRINTF("%i", 12);
	FT_PRINTF("%i", -12);
	FT_PRINTF("%p", (void *)84);
	FT_PRINTF("%p", (void *)-84);
	FT_PRINTF_SINGLE("%%");
	FT_PRINTF("%s", "hello");
	FT_PRINTF("%s", NULL);
	FT_PRINTF("%u", 932);
	FT_PRINTF("%u", -932);
	FT_PRINTF("%x", 7823);
	FT_PRINTF("%X", -7823);

	FT_PRINTF("%12c", 'a');
	FT_PRINTF("%12i", 12);
	FT_PRINTF("%12i", -12);
	FT_PRINTF("%12p", (void *)84);
	FT_PRINTF("%12p", (void *)-84);
	FT_PRINTF_SINGLE("%12%");
	FT_PRINTF("%12s", "hello");
	FT_PRINTF("%12s", NULL);
	FT_PRINTF("%12u", 932);
	FT_PRINTF("%12u", -932);
	FT_PRINTF("%12x", 7823);
	FT_PRINTF("%12X", -7823);

	FT_PRINTF("%012c", 'a');
	FT_PRINTF("%012i", 12);
	FT_PRINTF("%012i", -12);
	FT_PRINTF("%012p", (void *)84);
	FT_PRINTF("%012p", (void *)-84);
	FT_PRINTF_SINGLE("%012%");
	FT_PRINTF("%012s", "hello");
	FT_PRINTF("%012s", NULL);
	FT_PRINTF("%012u", 932);
	FT_PRINTF("%012u", -932);
	FT_PRINTF("%012x", 7823);
	FT_PRINTF("%012X", -7823);

	FT_PRINTF("%.12c", 'a');
	FT_PRINTF("%.12i", 12);
	FT_PRINTF("%.12i", -12);
	FT_PRINTF("%.12p", (void *)84);
	FT_PRINTF("%.12p", (void *)-84);
	FT_PRINTF_SINGLE("%.12%");
	FT_PRINTF("%.12s", "hello");
	FT_PRINTF("%.12s", NULL);
	FT_PRINTF("%.12u", 932);
	FT_PRINTF("%.12u", -932);
	FT_PRINTF("%.12x", 7823);
	FT_PRINTF("%.12X", -7823);

	FT_PRINTF("%12.6c", 'a');
	FT_PRINTF("%12.6i", 12);
	FT_PRINTF("%12.6i", -12);
	FT_PRINTF("%12.6p", (void *)84);
	FT_PRINTF("%12.6p", (void *)-84);
	FT_PRINTF_SINGLE("%12.6%");
	FT_PRINTF("%12.6s", "hello");
	FT_PRINTF("%12.6s", NULL);
	FT_PRINTF("%12.6u", 932);
	FT_PRINTF("%12.6u", -932);
	FT_PRINTF("%12.6x", 7823);
	FT_PRINTF("%12.6X", -7823);

	FT_PRINTF("%.c", 'a');
	FT_PRINTF("%.i", 12);
	FT_PRINTF("%.i", -12);
	FT_PRINTF("%.p", (void *)84);
	FT_PRINTF("%.p", (void *)-84);
	FT_PRINTF_SINGLE("%.%");
	FT_PRINTF("%.s", "hello");
	FT_PRINTF("%.s", NULL);
	FT_PRINTF("%.u", 932);
	FT_PRINTF("%.u", -932);
	FT_PRINTF("%.x", 7823);
	FT_PRINTF("%.X", -7823);

	FT_PRINTF("%012.2c", 'a');
	FT_PRINTF("%012.2i", 12);
	FT_PRINTF("%012.2i", -12);
	FT_PRINTF("%012.2p", (void *)84);
	FT_PRINTF("%012.2p", (void *)-84);
	FT_PRINTF_SINGLE("%012.2%");
	FT_PRINTF("%012.2s", "hello");
	FT_PRINTF("%012.2s", NULL);
	FT_PRINTF("%012.2u", 932);
	FT_PRINTF("%012.2u", -932);
	FT_PRINTF("%012.2x", 7823);
	FT_PRINTF("%012.2X", -7823);
	#else
	// one time tests
	#endif
	return (0);
}
