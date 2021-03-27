/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 00:37:09 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/10 17:26:39 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *s)
{
	char	*str;
	double	int_part;
	double	float_part;

	str = (char *)s;
	while (ft_isspace(*str))
		str++;
	int_part = (double)ft_atoi(str);
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str != '.' || !ft_isdigit(str[1]))
		return (int_part);
	str++;
	float_part = (double)ft_atoi(str);
	while (ft_isdigit(*str))
	{
		str++;
		float_part /= 10;
	}
	if (int_part < 0)
		return (int_part - float_part);
	return (int_part + float_part);
}
