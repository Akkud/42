/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:22:11 by pacharbo          #+#    #+#             */
/*   Updated: 2019/05/10 18:05:10 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			flag_sharp_binary(t_printf *data)
{
	char	*tmp;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (ft_strlen(data->res) % 8)
	{
		if (!(tmp = ft_strnew(8)))
			return (-1);
		memset(tmp, '0', 8 - ft_strlen(data->res) % 8);
		if (!(data->res = ft_sjoin3(&tmp, &data->res)))
			return (-1);
	}
	if (!(tmp = ft_strnew(ft_strlen(data->res) + ft_strlen(data->res) / 8)))
		return (-1);
	while ((tmp[b++] = data->res[a++]))
		if (data->res[a] && !(a % 8))
			tmp[b++] = ' ';
	ft_strdel(&data->res);
	data->res = tmp;
	return (data->res ? 1 : -1);
}

int			flag_sharp(t_printf *data)
{
	if (data->conv == 2 && data->res[0] != '0' &&
	!(data->res = ft_sjoin2("0", &data->res)))
		return (-1);
	if (data->conv == 4 && data->res[0] != '0' &&
	!(data->res = ft_sjoin2("0x", &data->res)))
		return (-1);
	if (data->conv == 5 && data->res[0] != '0' &&
	!(data->res = ft_sjoin2("0X", &data->res)))
		return (-1);
	return (1);
}

/*static int	flag_zero(t_printf *data)
{

}

static int	flag_minus(t_printf *data)
{

}*/

int			flag_space(t_printf *data)
{
	if (!(data->conv <= 1 || (data->conv >= 9 && data->conv <= 11)) ||
		(data->res[0] == '-') || data->flag[4])
		return (0);
	if (!(data->res = ft_sjoin2(" ", &data->res)))
		return (-1);
	return (1);
}

int			flag_plus(t_printf *data)
{
	if (!(data->conv <= 1 || (data->conv >= 9 && data->conv <= 11)) ||
		(data->res[0] == '-'))
		return (0);
	if (!(data->res = ft_sjoin2("+", &data->res)))
		return (-1);
	return (1);
}

int			precision_int(t_printf *data, long long int diff)
{
	char			*tmp;
	char			*tmp2;

	if (!(tmp = ft_strnew(diff + 2)))
		return (-1);
	if (data->res[0] >= '0' && data->res[0] <= '9')
	{
		ft_memset(tmp, '0', diff);
		data->res = ft_sjoin3(&tmp, &data->res);
	}
	else
	{
		ft_memset(tmp, '0', diff + 1);
		tmp[ft_strlen(tmp)] = data->res[0];
		tmp2 = data->res;
		data->res = ft_sjoin1(&tmp, data->res + 1);
		ft_strdel(&tmp2);
	}
	if (!data->res)
		return (-1);
	return (1);
}

int			precision(t_printf *data)
{
	char			*tmp;
	long long int	diff;

	diff = data->pr - ft_strlen(data->res);
	if (data->conv <= 5 && ((data->res[0] >= '0' &&
		data->res[0] <= '9' && diff > 0) || diff >= 0))
		return (precision_int(data, diff));
	else if (data->conv == 7)
		data->res[data->pr] = '\0';
	else if (data->conv == 12 && (long long int)ft_strlen(data->res) < data->pr)
	{
		if (!(tmp = ft_strnew(diff)))
			return (-1);
		ft_memset(tmp, '0', diff);
		if (!(data->res = ft_sjoin3(&tmp, &data->res)))
			return (-1);
	}
	return (1);
}

int			field_width(t_printf *data)
{
	long long int	diff;
	char			*tmp;

//	if (data->res)
//	{
		if ((diff = data->fw - ft_strlen(data->res)) < 0)
			return (0);
//	}
//	else
//		diff = data->fw;
	if (!(tmp = ft_strnew(diff)))
		return (-1);
	if (data->flag && data->flag[1] && !data->flag[2] && data->pr < 0 &&
		(data->conv <= 5 || (data->conv >= 9 && data->conv <= 11 )))
		ft_memset(tmp, '0', diff);
	else
		ft_memset(tmp, ' ', diff);
	if (data->flag && data->flag[2])
	{
		if (!(data->res = ft_sjoin3(&data->res, &tmp)))
			return (-1);
	}
	else if (!(data->res = ft_sjoin3(&tmp, &data->res)))
		return (-1);
	return (1);
}
