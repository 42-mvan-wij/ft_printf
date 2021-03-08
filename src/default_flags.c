/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   default_flags.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 22:20:59 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/07 22:23:12 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_default_flags(t_conv *conv)
{
	conv->e_pad_type = LEFT;
	conv->field_width = 0;
	conv->precision = -1;
	conv->e_type = UNSET;
}
