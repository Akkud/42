/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:08:39 by pacharbo          #+#    #+#             */
/*   Updated: 2019/05/20 17:02:09 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_init_data(t_printf **data)
{
	if (!*data && !(*data = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	(*data)->conv = 0;
	(*data)->flag = NULL;
	(*data)->fw = 0;
	(*data)->pr = -1;
	(*data)->lmod = 0;
	(*data)->res = NULL;
	return (1);
}

void			ft_free_data(t_printf *data)
{
	ft_memdel((void**)&data->flag);
	ft_memdel((void**)&data->res);
}

int				ft_getdata(char **fmt, t_printf **data)
{
	if (ft_init_data(data) < 0 || getflag(fmt, *data) < 0)
		return (-1);
	getfw(fmt, *data);
	getprec(fmt, *data);
	getlmod(fmt, *data);
	if (getconv(fmt, *data) < 0)
		return (-1);
	return (0);
}
