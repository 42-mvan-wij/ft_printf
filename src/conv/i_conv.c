/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/27 13:09:37 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../lib/libft/libft.h"
#include <unistd.h>

int	print_i(t_conv *conv, int i)
{
	char	*s1;
	char	*s2;
	int		len;
	int		has_sign;

	s1 = ft_itoa(i);
	s2 = precision_digits(conv->precision, s1);
	if (s1 != NULL)
		free(s1);
	if (s2 == NULL)
		return (-1);
	has_sign = s2[0] == '-' || s2[0] == '+';
	len = print_w_field_width(conv, s2, ft_strlen(s2), has_sign);
	free(s2);
	return (len);
}
