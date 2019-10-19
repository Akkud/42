/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:26 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:04:05 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 50
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../Libft/include/libft.h"
# include <stdio.h>

typedef	struct	s_printf
{
	int			conv;
	char		*flag;
	int			fw;
	int			pr;
	int			lmod;
	char		*res;
}				t_printf;

int				ft_getdata(char **fmt, t_printf **data);
int				getflag(char **fmt, t_printf *data);
void			getfw(char **fmt, t_printf *data);
void			getprec(char **fmt, t_printf *data);
void			getlmod(char **fmt, t_printf *data);
int				getconv(char **fmt, t_printf *data);
int				flag_sharp(t_printf *data);
int				flag_space(t_printf *data);
int				flag_plus(t_printf *data);
int				field_width(t_printf *data);
int				precision(t_printf *data);
void			ft_free_data(t_printf *data);
int				ft_printf(const char *format, ...);
int				ft_fill_buff(char buf[BUFF_SIZE], int a, t_printf *data,
				int *ret);
int				ft_display(char buf[BUFF_SIZE], int *a);
int				ft_percentcheck(char **fmt, va_list ap, t_printf **data);
int				conv_int(va_list ap, t_printf *data);
int				conv_int2(va_list ap, t_printf *data);
int				conv_octal(va_list ap, t_printf *data);
int				conv_octal2(va_list ap, t_printf *data);
int				conv_uint(va_list ap, t_printf *data);
int				conv_uint2(va_list ap, t_printf *data);
int				conv_hexalow(va_list ap, t_printf *data);
int				conv_hexalow2(va_list ap, t_printf *data);
int				conv_hexaup(va_list ap, t_printf *data);
int				conv_hexaup2(va_list ap, t_printf *data);
int				conv_uchar(va_list ap, t_printf *data);
int				conv_char_array(va_list ap, t_printf *data);
int				conv_pointer(va_list ap, t_printf *data);
int				conv_binary(va_list ap, t_printf *data);
int				conv_percent(va_list ap, t_printf *data);
int				conv_fdouble(va_list ap, t_printf *data);
int				conv_float(long double arg, t_printf *data, char *dec,
				char *tmp);
int				conv_edouble(va_list ap, t_printf *data);
int				conv_gdouble(va_list ap, t_printf *data);

#endif
