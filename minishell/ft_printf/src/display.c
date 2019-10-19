/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:13:08 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:05:05 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_display(char buf[BUFF_SIZE], int *a)
{
	int		ret;

	if (!*a)
		return (0);
	write(1, buf, *a);
	ret = *a;
	*a = 0;
	return (ret);
}

static int		ft_fill_nullchar(char buf[BUFF_SIZE], int a, t_printf *data,
				int *ret)
{
	int		i;

	i = 0;
	while (1)
	{
		if (a > BUFF_SIZE - 2)
			*ret += ft_display(buf, &a);
		buf[a++] = data->res[i++];
		if (!data->res[i - 1])
			break ;
	}
	return (a);
}

int				ft_fill_buff(char buf[BUFF_SIZE], int a, t_printf *data,
				int *ret)
{
	int			i;

	i = 0;
	if (data->conv == 6)
		while (1)
		{
			if (data->res[i] && data->fw <= i + 1)
				break ;
			else if (!data->res[i])
				return (ft_fill_nullchar(buf, a, data, ret));
			i++;
		}
	i = 0;
	while (data->res[i])
	{
		if (a > BUFF_SIZE - 2)
			*ret += ft_display(buf, &a);
		buf[a++] = data->res[i++];
	}
	return (a);
}
