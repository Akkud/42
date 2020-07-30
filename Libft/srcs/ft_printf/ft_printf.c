/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:28:15 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/07 17:19:16 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_dispatch(int (*conv[14]) (va_list ap, t_printf *data),
				int (*flag[5]) (t_printf *data))
{
	conv[0] = conv_int;
	conv[1] = conv_int;
	conv[2] = conv_octal;
	conv[3] = conv_uint;
	conv[4] = conv_hexalow;
	conv[5] = conv_hexaup;
	conv[6] = conv_uchar;
	conv[7] = conv_char_array;
	conv[8] = conv_pointer;
	conv[9] = conv_fdouble;
	conv[10] = conv_edouble;
	conv[11] = conv_gdouble;
	conv[12] = conv_binary;
	conv[13] = conv_percent;
	flag[0] = flag_sharp;
	flag[3] = flag_space;
	flag[4] = flag_plus;
}

static int		conv_main(va_list ap, t_printf *data)
{
	static int	(*conv[14]) (va_list ap, t_printf *data);
	static int	(*flag[5]) (t_printf *data);
	int			a;

	a = -1;
	ft_dispatch(conv, flag);
	if (((conv[data->conv])(ap, data)) < 0)
		return (-1);
	if (data->pr >= 0 && precision(data) < 0)
		return (-1);
	if (data->flag)
		while (++a < 5)
			if (a != 1 && a != 2 && data->flag[a] && (flag[a](data) < 0))
				return (-1);
	if (data->fw && field_width(data) < 0)
		return (-1);
	return (0);
}

int				ft_percentcheck(char **fmt, va_list ap, t_printf **data)
{
	if (ft_getdata(fmt, data) < 0 || conv_main(ap, *data) < 0)
	{
		ft_free_data(*data);
		return (-1);
	}
	return (1);
}

static int		parser_n_co(char *fmt, va_list ap, t_printf **data)
{
	char		buf[BUFF_SIZE];
	int			ret;
	int			a;

	a = 0;
	ret = 0;
	while (*fmt)
		if (*fmt == '%')
		{
			fmt++;
			if (ft_percentcheck(&fmt, ap, data) < 0)
				return (-1);
			a = ft_fill_buff(buf, a, *data, &ret);
			ft_free_data(*data);
		}
		else
		{
			if (a > BUFF_SIZE - 2)
				ret += ft_display(buf, &a);
			if (*fmt)
				buf[a++] = *fmt++;
		}
	ret += ft_display(buf, &a);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*fmt;
	int			ret;
	t_printf	*data;

	data = NULL;
	fmt = (char*)format;
	va_start(ap, format);
	ret = parser_n_co(fmt, ap, &data);
	free(data);
	va_end(ap);
	return (ret);
}
