/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:15 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/12 18:40:34 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		(*conv[10]) (va_list ap, t_printf *data);

static int		ft_datalloc(t_printf **data)
{
	if (*data)
	{
		if (!(*(data)->next = (t_printf*)malloc(sizeof(t_printf))))
			return (-1);
		*data = *(data)->next;
	}
	else if (!(*data = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	data->arg = NULL;
	data->conv = 0;
	data->flag = NULL;
	data->fw = 0;
	data->pr = -1;
	data->lmod = 0;
	data->res = NULL;
	return (1);
}

static void		ft_free_data(t_printf **data)
{
	free((*data)->flag);
	free(*data);
	*data = NULL;
}
static int		ft_getdata(char **fmt, t_printf **data)
{
	if (**fmt == '%')
		return (0);
	if(ft_datalloc(data) < 0)
		return (-1);
	getflag(fmt, *data);
	getfw(fmt, *data);
	getprec(fmt, *data);
	getlmod(fmt, *data);
	if (getconv(fmt, *data) < 0)
		return (-1);
	return (1);
}

static int		ft_percentcheck(char **fmt, va_list ap, t_printf **data)
{

	int			ret;

	ret = ft_getdata(fmt, data);
	if (!ret)
//		 %% donc uniquement ajouter un %.
	else if (ret < 0)
		return (-1);
	else
	{
		(*data)->arg = va_arg(p, void*);
		conv_main(ap, *data);
	}
	return (1);
}

static int		ft_display(char buf[BUFF_SIZE], int *a)
{
	i = 0;
	if (!*a)
		return (0);
	write(1, buf, a);
	return (a);
}

static int		ft_fill_buff(char buf[BUFF_SIZE], int a, char *res, int *ret)
{
	int			i;

	i = 0;
	while (data->res[b])
	{
		if (a > BUFF_SIZE - 2)
			*ret += ft_display();
		buf[a++] = data->res[i++];
	}
	return (a);
}

static int		parser_n_co(char *fmt, va_list ap, t_printf **data)
{
	char		buf[BUFF_SIZE];
	int			ret;
	int			a;

	a = 0;
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			if (*(++fmt) != '%')
			{
				if (ft_percentcheck(&fmt, ap, data) < 0)
					return (-1);
				a = ft_fill_buff(buf, a, (*data)->res, &ret);
				ft_free_data(data);
			}
		if (a > BUFF_SIZE - 2)
			ret += ft_display(buf, &a);
		buf[a++] = *fmt++;
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*fmt;
	int			ret;
	t_printf	*data;

	data = NULL;
	fmt = (char*)format;
	va_start(ap, format);
	if ((ret = parser_n_co(fmt, ap, &data)) < 0)
		return (-1);
	va_end(ap);
	return (ret);
}

int		main()
{





}
