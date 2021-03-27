/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/27 13:09:31 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../lib/libft/libft.h"
#include <unistd.h>

int	print_x(t_conv *conv, unsigned int i, int cap)
{
	char	*s1;
	char	*s2;
	int		len;

	s1 = ft_utoa_basei(i, 16, cap);
	s2 = precision_digits(conv->precision, s1);
	if (s1 != NULL)
		free(s1);
	if (s2 == NULL)
		return (-1);
	len = print_w_field_width(conv, s2, ft_strlen(s2), s2[0] == '+');
	free(s2);
	return (len);
}
