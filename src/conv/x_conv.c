/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/11 13:49:58 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../lib/libft/libft.h"
#include <unistd.h>

int	print_x(t_conv *conv, unsigned int i, int cap)
{
	char	*s;

	s = ft_utoa_basei(i, 16, cap);
	if (s == NULL)
		return (-1);
	return (print_with_field_width(conv, s, ft_strlen(s)));
}
