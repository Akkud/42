/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:35:20 by pacharbo          #+#    #+#             */
/*   Updated: 2019/05/20 17:47:49 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int			conv_float(long double arg, t_printf *data, char *dec, char *tmp)
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
	return (conv_float(arg, data, dec, tmp));
}
