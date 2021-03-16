/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:19:27 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/16 15:13:24 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stdbool.h>

static int	print_padding(int len, char c)
{
	char	*padding;
	int		write_len;

	if (len <= 0)
		return (0);
	padding = malloc(len);
	if (padding == NULL)
		return (-1);
	ft_memset(padding, c, len);
	write_len = write(1, padding, len);
	free(padding);
	return (write_len);
}

static int	print_field_width_left(t_conv *conv, char *str, int len)
{
	if (print_padding(conv->field_width - len, ' ') < 0)
		return (-1);
	if (write(1, str, len) < 0)
		return (-1);
	return (conv->field_width);
}

static int	print_field_width_right(t_conv *conv, char *str, int len)
{
	if (write(1, str, len) < 0)
		return (-1);
	if (print_padding(conv->field_width - len, ' ') < 0)
		return (-1);
	return (conv->field_width);
}

static int	print_field_width_zero(t_conv *conv, char *str, int len, int skip)
{
	if (skip > 0)
	{
		if (write(1, str, skip) < 0)
			return (-1);
	}
	if (print_padding(conv->field_width - len, '0') < 0)
		return (-1);
	if (write(1, str + skip, len - skip) < 0)
		return (-1);
	return (conv->field_width);
}

int	print_with_field_width(t_conv *conv, char *str, int len, int zero_skip)
{
	if (len >= conv->field_width)
		return (write(1, str, len));
	if (conv->e_pad_type == LEFT)
		return (print_field_width_left(conv, str, len));
	if (conv->e_pad_type == RIGHT)
		return (print_field_width_right(conv, str, len));
	if (conv->e_pad_type == ZERO)
		return (print_field_width_zero(conv, str, len, zero_skip));
	return (-1);
}
