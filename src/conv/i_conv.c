/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/11 13:23:55 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../lib/libft/libft.h"
#include <unistd.h>

int	print_i(t_conv *conv, int i)
{
	char	*s;

	s = ft_itoa(i);
	if (s == NULL)
		return (-1);
	return (print_with_field_width(conv, s, ft_strlen(s)));
}
