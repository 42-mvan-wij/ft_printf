/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 14:40:20 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/15 16:22:36 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_ft_printf_conv
{
	int	field_width;
	int	precision;
	enum {
		LEFT,
		RIGHT,
		ZERO
	}	e_pad_type;
	enum {
		UNSET,
		PCT,
		CHAR,
		STRING,
		INT,
		UINT,
		//FLOAT,
		HEX_LOW,
		HEX_CAP,
		PTR
	}	e_type;
}		t_conv;

void	set_default_flags(t_conv *conv);
char	*parse_conversion(char *format, t_conv *conv, va_list ap);
int		print_with_field_width(t_conv *conv, char *str, int len);
char	*precision_digits(int precision, char *str);
char	*precision_chars(int precision, char *str);
int		print_pct(t_conv *conv);
int		print_c(t_conv *conv, char c);
int		print_s(t_conv *conv, char *str);
int		print_i(t_conv *conv, int i);
int		print_u(t_conv *conv, unsigned int i);
int		print_x(t_conv *conv, unsigned int i, int cap);
int		print_p(t_conv *conv, void *p);
char	*print_part(char *format, va_list ap, int *len, t_conv *tmp_conv_arg);
int		ft_printf(const char *format, ...);

#endif
