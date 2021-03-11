/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/11 23:12:07 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../lib/libft/libft.h"
#include <unistd.h>

int	print_s(t_conv *conv, char *str)
{
	char	*s;
	int		len;

	s = precision_chars(conv->precision, str);
	len = print_with_field_width(conv, s, ft_strlen(s));
	free(s);
	return (len);
}
