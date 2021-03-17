/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_conv.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 23:14:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/17 13:56:17 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../../lib/libft/libft.h"
#include <unistd.h>

int	print_p(t_conv *conv, void *p)
{
	char	*s1;
	char	*s2;
	int		len;

	s1 = ft_utoa_basei((unsigned long)p, 16, 0);
	s2 = precision_digits(conv->precision, s1);
	if (s1 != NULL)
		free(s1);
	s1 = ft_strjoin("0x", s2);
	if (s2 != NULL)
		free(s2);
	if (s1 == NULL)
		return (-1);
	len = print_with_field_width(conv, s1, ft_strlen(s1), 2);
	free(s1);
	return (len);
}
