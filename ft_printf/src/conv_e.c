/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:38:49 by pacharbo          #+#    #+#             */
/*   Updated: 2019/05/20 17:52:56 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int			conv_edouble(va_list ap, t_printf *data)
{
	long double		arg;

	if (data->lmod == 5)
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	data->pr = data->pr == -1 ? 6 : data->pr;
	return (conv_exp(arg, data));
}
