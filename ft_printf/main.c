/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:15 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/30 19:59:10 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

static void		ft_free_data(t_printf **data)
{
	free((*data)->flag);
	free((*data)->res);
}

static int		ft_getdata(char **fmt, t_printf **data)
{
	if (ft_init_data(data) < 0 || getflag(fmt, *data) < 0)
		return (-1);
	getfw(fmt, *data);
	getprec(fmt, *data);
	getlmod(fmt, *data);
	if (getconv(fmt, *data) < 0)
		return (-1);
	write(1, "flags = [", 9);
	write(1, &((*data)->flag[0]), 1);
	write(1, &((*data)->flag[1]), 1);
	write(1, &((*data)->flag[2]), 1);
	write(1, &((*data)->flag[3]), 1);
	write(1, &((*data)->flag[4]), 1);
	printf("]\nfw = %i\nprec = %i\nlmod = %i\nconv = %i\n", (*data)->fw, (*data)->pr, (*data)->lmod, (*data)->conv);
	return (0);
}

static int		ft_percentcheck(char **fmt, va_list ap, t_printf **data)
{
	if (ft_getdata(fmt, data) < 0)
		return (-1);
	if (conv_main(ap, *data) < 0)
		return (-1);
	return (1);
}

static int		ft_display(char buf[BUFF_SIZE], int *a)
{
	int		ret;

	if (!*a)
		return (0);
	write(1, buf, *a);
	ret = *a;
	*a = 0;
	return (ret);
}

static int		ft_fill_buff(char buf[BUFF_SIZE], int a, char *res, int *ret)
{
	int			i;

	i = 0;
	while (res[i])
	{
		if (a > BUFF_SIZE - 2)
			*ret += ft_display(buf, &a);
		buf[a++] = res[i++];
	}
	return (a);
}

static int		parser_n_co(char *fmt, va_list ap, t_printf **data)
{
	char		buf[BUFF_SIZE];
	int			ret;
	int			a;
	char		*teste;

	teste = fmt;
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
		if (*fmt)
			buf[a++] = *fmt++;
	}
	ret += ft_display(buf, &a);
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

int				main(void)
{
//	char	*str = "test";
	long double		flotte = 3.006568435343543545454646545642;

//	ft_printf("coucou");
//	ft_printf("%s", str);
//	printf("printf : [%s]", str);
//	ft_printf("% 0+-#10.5hhs", str);
	ft_printf("cce = %.19Lf\n", flotte);
	printf("vre = %.19Lf\n", flotte);
	return (0);
}
