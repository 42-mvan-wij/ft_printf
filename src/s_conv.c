/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/08 00:29:35 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../lib/libft/libft.h"
#include <unistd.h>

int	print_s(t_conv *conv, char *str)
{
	return (print_with_field_width(conv, str, ft_strlen(str)));
}