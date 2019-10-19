/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:35:20 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:04:49 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

int			ft_ilen(long long int nb)
{
	int a;

	a = 1;
	while (nb / 10 > 0)
	{
		a++;
		nb /= 10;
	}
	return (a);
}

int			conv_float(long double arg, t_printf *d, char *dec, char *tmp)
{
	char			*ent;
	long double		a;

	a = arg;
	if (!d->pr)
	{
		tmp = d->flag && d->flag[0] ? ft_strdup(".") : ft_strnew(0);
		d->res = ft_lltoa(arg + 0.5);
		return ((d->res = ft_sjoin3(&d->res, &tmp)) ? 1 : -1);
	}
	if (ft_ilen((arg - (long long int)arg) * ft_power(10, d->pr) + 0.5)
	> d->pr)
		arg += 1;
	if (!(ent = ft_lltoa(arg)) ||
	!(dec = ft_lltoa((arg - (long long int)arg) * ft_power(10, d->pr) + 0.5)))
		ft_strdel(&ent);
	else if (ft_strlen(dec) < (size_t)d->pr && !ft_zeroadd(d, &dec, &tmp))
		return (-1);
	if (a != arg && (tmp = ft_strdup(dec + 1)))
	{
		ft_strdel(&dec);
		dec = tmp;
	}
	tmp = ft_sjoin1(&ent, ".");
	return ((d->res = ft_sjoin3(&tmp, &dec)) ? 1 : -1);
}

int			conv_fdouble(va_list ap, t_printf *data)
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
	if (arg < 0)
	{
		arg *= -1;
		if (!(conv_float(arg, data, dec, tmp))
		|| !(data->res = ft_sjoin2("-", &data->res)))
			return (-1);
		return (1);
	}
	return (conv_float(arg, data, dec, tmp));
}
