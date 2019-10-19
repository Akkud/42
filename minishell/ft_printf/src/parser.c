/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:26:42 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:05:28 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		getflag(char **fmt, t_printf *data)
{
	int		a;
	char	flag[6];

	a = -1;
	ft_strcpy(flag, "#0- +");
	while (flag[++a])
		if (**fmt == flag[a])
		{
			if (data->flag == NULL && !(data->flag = ft_strnew(5)))
				return (-1);
			data->flag[a] = flag[a];
			a = -1;
			fmt[0]++;
		}
	return (0);
}

void	getfw(char **fmt, t_printf *data)
{
	if (!(**fmt >= '1' && **fmt <= '9'))
		return ;
	data->fw = ft_atoi(*fmt);
	while (**fmt >= '0' && **fmt <= '9')
		fmt[0]++;
}

void	getprec(char **fmt, t_printf *data)
{
	if (**fmt != '.')
		return ;
	fmt[0]++;
	data->pr = ft_atoi(*fmt);
	if (data->pr < 0)
	{
		data->pr = 0;
		fmt[0]++;
	}
	while (**fmt >= '0' && **fmt <= '9')
		fmt[0]++;
}

int		getconv(char **fmt, t_printf *data)
{
	int		a;
	char	conv[15];

	ft_strcpy(conv, "diouxXcspfegb%");
	a = -1;
	while (conv[++a] && **fmt)
		if (**fmt == conv[a])
		{
			data->conv = a;
			fmt[0]++;
			return (1);
		}
		else if (**fmt == '*')
			break ;
		else if (!conv[a + 1])
		{
			fmt[0]++;
			a = -1;
		}
	return (-1);
}
