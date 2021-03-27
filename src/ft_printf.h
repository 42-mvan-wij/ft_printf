/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 14:40:20 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/27 13:09:25 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

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
		HEX_LOW,
		HEX_CAP,
		PTR,
		NBR
	}	e_type;
}		t_conv;

void	set_default_flags(t_conv *conv);
char	*parse_conversion(char *format, t_conv *conv, va_list ap);
int		print_w_field_width(t_conv *conv, char *str, size_t len, int zero_skip);
char	*precision_digits(int precision, char *str);
char	*precision_chars(int precision, char *str);
int		print_pct(t_conv *conv);
int		print_c(t_conv *conv, char c);
int		print_s(t_conv *conv, char *str);
int		print_i(t_conv *conv, int i);
int		print_u(t_conv *conv, unsigned int i);
int		print_x(t_conv *conv, unsigned int i, int cap);
int		print_p(t_conv *conv, void *p);
int		save_len(int len, int *dst);
char	*print_part(char *format, va_list ap, int *len);
int		ft_printf(const char *format, ...);

#endif
