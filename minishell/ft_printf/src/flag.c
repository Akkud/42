/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:22:11 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:05:11 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
		ft_memset(tmp, '0', 8 - ft_strlen(data->res) % 8);
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
	if (data->conv == 4 && data->res[0] && data->res[0] != '0' &&
	!(data->res = ft_sjoin2("0x", &data->res)))
		return (-1);
	if (data->conv == 5 && data->res[0] && data->res[0] != '0' &&
	!(data->res = ft_sjoin2("0X", &data->res)))
		return (-1);
	return (1);
}

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
