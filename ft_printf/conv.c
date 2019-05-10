/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:46 by pacharbo          #+#    #+#             */
/*   Updated: 2019/05/10 17:40:07 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	conv_int(va_list ap, t_printf *data)
{
	long long int		arg;

	if (data->lmod == 3)
	{
		arg = (long long int)va_arg(ap, long int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	else
	{
		arg = (long long int)va_arg(ap, int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	return (1);
}

static int	conv_octal(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	else
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	return (1);
}

static int	conv_uint(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	else
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	return (1);
}

static int	conv_hexalow(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	else
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	return (1);
}

static int	conv_hexaup(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	else
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	return (1);
}

static int	conv_uchar(va_list ap, t_printf *data)
{
	unsigned char	arg;

	arg = (unsigned char)va_arg(ap, int);
	if (!(data->res = ft_strnew(1)))
		return (-1);
	data->res[0] = arg;
	return (1);
}

static int	conv_char_array(va_list ap, t_printf *data)
{
	const char		*arg;

	arg = va_arg(ap, const char*);
	if (!(data->res = ft_strdup(arg)))
		return (-1);
	if (data->pr >= 0 && data->pr < (int)ft_strlen(data->res))
		data->res[data->pr] = '\0';
	return (1);
}

static int	conv_pointer(va_list ap, t_printf *data)
{
	void	*arg;
	char	*tmp;

	if (!(tmp = ft_strdup("0x")))
		return (-1);
	arg = va_arg(ap, void*);
	if (!(data->res = ft_strjoin(tmp,
		ft_ulltoa_base((long long unsigned int)arg, "0123456789abcdef"))))
		return (-1);
	free(tmp);
	return (1);
}

static int	ft_zeroadd(t_printf *data, char **dec, char **tmp)
{
	char	*zeros;

	ft_memdel((void**)tmp);
	if (!(*dec && ft_strlen(*dec) < (size_t)data->pr))
		return (0);
	*tmp = *dec;
	if (!(zeros = ft_strnew(data->pr - ft_strlen(*dec))))
	{
		ft_memdel((void**)dec);
		return (-1);
	}
	ft_memset(zeros, 48, data->pr - ft_strlen(*dec));
	if (!(*dec = ft_strjoin(zeros, *dec)))
	{
		ft_memdel((void**)tmp);
		return (-1);
	}
	ft_memdel((void**)tmp);
	return (1);
}

static int	ft_overfloat(t_printf *data, char **ent, char **dec, int a)
{
	char	*zeros;
	char	*tmp;

	tmp = *dec;
	if (!*ent || !*dec || !(zeros = ft_strnew(data->pr - a)))
	{
		ft_memdel((void**)ent);
		ft_memdel((void**)dec);
		return (-1);
	}
	ft_memset(zeros, 48, data->pr - a);
	if (!(*dec = ft_strjoin(*dec, zeros)))
		ft_memdel((void**)&zeros);
	if ((ft_zeroadd(data, dec, &tmp)) < 0)
		ft_memdel((void**)&zeros);
	if (!(tmp = ft_sjoin1(ent, ".")))
		ft_memdel((void**)&zeros);
	if (!(data->res = ft_sjoin3(&tmp, dec)))
		ft_memdel((void**)&zeros);
	if (!zeros)
		return (-1);
	ft_memdel((void**)&zeros);
	return (1);
}

static int	conv_float(long double arg, t_printf *data, char *dec, char *tmp)
{
	char			*ent;
	int				a;

	a = -1;
	if (!data->pr)
	{
		tmp = data->flag && data->flag[0] ? ft_strdup(".") : ft_strnew(0);
		data->res = ft_lltoa(arg + 0.5);
		return ((data->res = ft_sjoin3(&data->res, &tmp)) ? 1 : -1);
	}
	while (++a < data->pr)
		if (((arg - (long long)arg) * ft_power(10, a + 1) + 0.5) <
			((arg - (long long)arg) * ft_power(10, a) + 0.5))
			break ;
	if (!(ent = ft_lltoa(arg)) ||
		!(dec = ft_lltoa((arg - (long long int)arg) * ft_power(10, a) + 0.5)))
		ft_memdel((void*)ent);
	if (a < data->pr)
		return (ft_overfloat(data, &ent, &dec, a));
	else if (ft_strlen(dec) < (size_t)a)
		if (!ft_zeroadd(data, &dec, &tmp))
			return (-1);
	tmp = ft_sjoin1(&ent, ".");
	return ((data->res = ft_sjoin3(&tmp, &dec)) ? 1 : -1);
}

static int	conv_fdouble(va_list ap, t_printf *data)
{
	long double		arg;
	char			*dec;
	char			*tmp;

	if (data->lmod == 5)
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	dec = NULL;
	tmp = NULL;
	if (data->pr == -1)
		data->pr = 6;
	return (conv_float(arg, data, dec, tmp));
}

static int	conv_exp(long double flt, t_printf *data)
{
	long double		a;
	long long int	exp;
	char			*tmp;

	a = flt < 1 ? 10 : 0.1;
	exp = 0;
	while ((flt >= 10 || flt < 1) && ++exp)
		flt *= a;
	if (!conv_float(flt, data, NULL, NULL))
		return (-1);
	tmp = ft_lltoa(exp);
	tmp = exp / 10 ? tmp : ft_sjoin2("0", &tmp);
	tmp = a < 1 ? ft_sjoin2("e+", &tmp) : ft_sjoin2("e-", &tmp);
	if (!(data->res = ft_sjoin3(&data->res, &tmp)))
		return (-1);
	return (1);
}

static int	conv_gexp(long double flt, t_printf *data)
{
	long double		a;
	long long int	exp;
	char			*tmp;
	int				i;

	a = flt < 1 ? 10 : 0.1;
	exp = 0;
	while ((flt >= 10 || flt < 1) && ++exp)
		flt *= a;
	if (!conv_float(flt, data, NULL, NULL))
		return (-1);
	i = ft_strlen(data->res);
	while (data->res[--i] == '0' && !(data->flag && data->flag[0]))
		data->res[i] = '\0';
	if (data->res[i] == '.' && !(data->flag && data->flag[0]))
		data->res[i] = '\0';
	tmp = ft_lltoa(exp);
	tmp = exp / 10 ? tmp : ft_sjoin2("0", &tmp);
	tmp = a < 1 ? ft_sjoin2("e+", &tmp) : ft_sjoin2("e-", &tmp);
	if (!(data->res = ft_sjoin3(&data->res, &tmp)))
		return (-1);
	return (1);
}

static int	conv_edouble(va_list ap, t_printf *data)
{
	long double		arg;

	if (data->lmod == 5)
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	data->pr = data->pr == -1 ? 6 : data->pr;
	return (conv_exp(arg, data));
}

static int	conv_gup(long double arg, long long int exp, t_printf *data)
{
	long long int	i;
	long double		flt;

	flt = arg;
	while (flt > 10 && ++exp)
		flt /= 10;
	if (exp >= data->pr)
	{
		data->pr = data->pr ? data->pr - 1 : data->pr;
		return (conv_gexp(arg, data));
	}
	data->pr -= exp + 1;
	if (!(conv_float(arg, data, NULL, NULL)))
		return (-1);
	i = ft_strlen(data->res);
	if (!(data->flag && data->flag[0]))
	{
		while (data->res[--i] == '0')
			data->res[i] = '\0';
		if (data->res[i] == '.')
			data->res[i] = '\0';
	}
	return (1);
}

static int	conv_glow(long double arg, long long int exp, t_printf *data)
{
	long long int	i;
	long double		flt;

	flt = arg;
	while (flt < 1 && ++exp)
		flt *= 10;
	if (exp > 4)
	{
		data->pr = data->pr ? data->pr - 1 : data->pr;
		return (conv_gexp(arg, data));
	}
	data->pr += exp - 1;
	if (!(conv_float(arg, data, NULL, NULL)))
		return (-1);
	i = ft_strlen(data->res);
	if (!(data->flag && data->flag[0]))
	{
		while (data->res[--i] == '0')
			data->res[i] = '\0';
		if (data->res[i] == '.')
			data->res[i] = '\0';
	}
	return (1);
}

static int	conv_gdouble(va_list ap, t_printf *data)
{
	long double		arg;
	long long int	exp;

	exp = 0;
	if (data->lmod == 5)
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	data->pr = data->pr < 0 ? 6 : data->pr;
	if (arg < 1)
		return (conv_glow(arg, exp, data));
	else
		return (conv_gup(arg, exp, data));
	return (1);
}

static int	conv_binary(va_list ap, t_printf *data)
{
	void	*arg;

	arg = va_arg(ap, void*);
	if (!(data->res = ft_ulltoa_base((long long unsigned int)arg, "01")))
		return (-1);
	return (1);
}

static void	ft_dispatch(int (*conv[13]) (va_list ap, t_printf *data),
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
	flag[0] = flag_sharp;
//	flag[1] = flag_zero;
//	flag[2] = flag_minus;
	flag[3] = flag_space;
	flag[4] = flag_plus;
}

int			conv_main(va_list ap, t_printf *data)
{
	static int	(*conv[13]) (va_list ap, t_printf *data);
	static int	(*flag[5]) (t_printf *data);
	int			a;

	a = -1;
	ft_dispatch(conv, flag);
	if (((conv[data->conv])(ap, data)) < 0)
		return (-1);
	if (data->pr >= 0 && precision(data) < 0)
		return (-1);
	while (++a < 5)
		if (a != 1 && a != 2 && data->flag[a] && (flag[a](data) < 0))
			return (-1);
	if (data->fw && field_width(data) < 0)
		return (-1);
	return (0);
}
