/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:19:27 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/08 00:30:49 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../lib/libft/libft.h"
#include <unistd.h>

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

int	print_with_field_width(t_conv *conv, char *str, int len)
{
	int	write_len;

	if (len >= conv->field_width)
		return (write(1, str, len));
	write_len = 0;
	if (conv->e_pad_type == LEFT)
		write_len = print_padding(conv->field_width - len, ' ');
	else if (conv->e_pad_type == ZERO)
		write_len = print_padding(conv->field_width - len, '0');
	if (write_len < 0)
		return (-1);
	write_len = write(1, str, len);
	if (write_len < 0)
		return (-1);
	if (conv->e_pad_type == RIGHT)
	{
		write_len = print_padding(conv->field_width - len, ' ');
		if (write_len < 0)
			return (-1);
	}
	return (conv->field_width);
}