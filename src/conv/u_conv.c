/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/11 23:14:10 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../lib/libft/libft.h"
#include <unistd.h>

int	print_u(t_conv *conv, unsigned int i)
{
	char	*s1;
	char	*s2;
	int		len;

	s1 = ft_utoa(i);
	s2 = precision_digits(conv->precision, s1);
	if (s1 != NULL)
		free(s1);
	if (s2 == NULL)
		return (-1);
	len = print_with_field_width(conv, s2, ft_strlen(s2));
	free(s2);
	return (len);
}
