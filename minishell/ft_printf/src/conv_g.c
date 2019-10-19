/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:40:54 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:04:54 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

int			conv_gdouble(va_list ap, t_printf *data)
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
