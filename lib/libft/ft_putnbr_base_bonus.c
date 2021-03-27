/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 12:09:02 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/24 17:17:23 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long long nbr, char *basechars)
{
	int			base;
	long long	pow;
	int			len;
	int			is_neg;

	base = ft_strlen(basechars);
	if (base < 2)
		return (-1);
	pow = 1;
	while (nbr / base / pow != 0)
		pow *= base;
	is_neg = (nbr < 0);
	if (is_neg)
		ft_putchar_fd('-', 1);
	len = 0;
	while (pow != 0)
	{
		if (is_neg)
			ft_putchar_fd(basechars[-nbr / pow % base], 1);
		else
			ft_putchar_fd(basechars[nbr / pow % base], 1);
		pow /= base;
		len++;
	}
	return (len + is_neg);
}
