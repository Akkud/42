/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:30:38 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:05:17 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			precision_int(t_printf *data, long long int diff)
{
	char			*tmp;
	char			*tmp2;

	if (!(tmp = ft_strnew(diff + 2)))
		return (-1);
	if ((data->res[0] >= '0' && data->res[0] <= '9') ||
		(data->res[0] >= 'a' && data->res[0] <= 'f') ||
		(data->res[0] >= 'A' && data->res[0] <= 'F'))
	{
		ft_memset(tmp, '0', diff);
		data->res = ft_sjoin3(&tmp, &data->res);
	}
	else
	{
		ft_memset(tmp, '0', diff + 2);
		tmp[0] = data->res[0];
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
	if (data->res[0] == '0' && !data->pr && data->conv != 9)
		data->res[0] = '\0';
	return (1);
}

int			field_width_hexa(t_printf *data, char **str)
{
	int		a;
	char	*tmp;

	a = 0;
	tmp = data->res;
	if (!(*str = ft_sjoin2("0x", str)))
	{
		ft_strdel(&data->res);
		return (-1);
	}
	if (!(data->res = ft_sjoin1(str, data->res + 2)))
	{
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&tmp);
	return (1);
}

int			field_width_zero(t_printf *data, char **str, long long int diff)
{
	char	*tmp;
	char	*tmp2;

	tmp = *str;
	ft_memset(tmp, '0', diff);
	if (data->flag && data->flag[0] && data->flag[1] && !data->flag[2] &&
		data->conv >= 4 && data->conv <= 5)
		return (field_width_hexa(data, str));
	if (!((data->res[0] >= '0' && data->res[0] <= '9') ||
		(data->res[0] >= 'a' && data->res[0] <= 'f') ||
		(data->res[0] >= 'A' && data->res[0] <= 'F')))
	{
		tmp2 = ft_strnew(1);
		tmp2[0] = data->res[0];
		tmp = ft_sjoin3(&tmp2, &tmp);
		tmp2 = data->res;
		if (!(data->res = ft_sjoin1(&tmp, data->res + 1)))
			return (-1);
		ft_strdel(&tmp2);
	}
	else if (!(data->res = ft_sjoin3(&tmp, &data->res)))
		return (-1);
	return (1);
}

int			field_width(t_printf *data)
{
	long long int	diff;
	char			*tmp;

	if ((diff = data->fw - ft_strlen(data->res)) <= 0)
		return (0);
	diff = data->conv == 6 && !data->res[0] ? diff - 1 : diff;
	if (!(tmp = ft_strnew(diff)))
		return (-1);
	if (data->flag && data->flag[1] && !data->flag[2] && data->pr < 0 &&
		(data->conv <= 5 || (data->conv >= 9 && data->conv <= 11)))
		return (field_width_zero(data, &tmp, diff));
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
