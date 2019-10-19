/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:17:50 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:05:43 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	hlmod(char **fmt, t_printf *data)
{
	if (**fmt == 'h')
	{
		data->lmod = 1;
		fmt[0]++;
	}
	else
		data->lmod = 2;
}

void	llmod(char **fmt, t_printf *data)
{
	if (**fmt == 'l')
	{
		data->lmod = 4;
		fmt[0]++;
	}
	else
		data->lmod = 3;
}

void	getlmod(char **fmt, t_printf *data)
{
	if (**fmt == 'h' && (fmt[0]++))
		hlmod(fmt, data);
	else if (**fmt == 'l' && (fmt[0]++))
		llmod(fmt, data);
	else if (**fmt == 'L')
	{
		data->lmod = 5;
		fmt[0]++;
	}
	else if (**fmt == 'j')
	{
		data->lmod = 4;
		fmt[0]++;
	}
}
