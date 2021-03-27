/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/27 13:09:28 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	print_c(t_conv *conv, char c)
{
	return (print_w_field_width(conv, &c, 1, 0));
}
