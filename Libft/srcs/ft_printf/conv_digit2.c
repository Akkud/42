/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_digit2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:07:48 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 07:00:30 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_int2(va_list ap, t_printf *data)
{
	long long int		arg;

	if (data->lmod == 1)
	{
		arg = (long long int)va_arg(ap, int);
		if (!(data->res = ft_lltoa((char)arg)))
			return (-1);
	}
	else if (data->lmod == 2)
	{
		arg = (long long int)va_arg(ap, int);
		if (!(data->res = ft_lltoa((short int)arg)))
			return (-1);
	}
	return (1);
}

int		conv_octal2(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 1)
	{
		arg = (long long unsigned int)va_arg(ap, int);
		if (!(data->res = ft_lltoa_base((unsigned char)arg, "01234567")))
			return (-1);
	}
	else if (data->lmod == 2)
	{
		arg = (long long unsigned int)va_arg(ap, int);
		if (!(data->res = ft_lltoa_base((unsigned short int)arg, "01234567")))
			return (-1);
	}
	return (1);
}

int		conv_uint2(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 1)
	{
		arg = (long long unsigned int)va_arg(ap, int);
		if (!(data->res = ft_lltoa_base((unsigned char)arg, "0123456789")))
			return (-1);
	}
	else if (data->lmod == 2)
	{
		arg = (long long int)va_arg(ap, int);
		if (!(data->res = ft_lltoa_base((unsigned short int)arg, "0123456789")))
			return (-1);
	}
	return (1);
}

int		conv_hexalow2(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 1)
	{
		arg = (long long unsigned int)va_arg(ap, int);
		if (!(data->res = ft_lltoa_base((unsigned char)arg,
			"0123456789abcdef")))
			return (-1);
	}
	else if (data->lmod == 2)
	{
		arg = (long long unsigned int)va_arg(ap, int);
		if (!(data->res = ft_lltoa_base((unsigned short int)arg,
			"0123456789abcdef")))
			return (-1);
	}
	return (1);
}

int		conv_hexaup2(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 1)
	{
		arg = (long long unsigned int)va_arg(ap, int);
		if (!(data->res = ft_lltoa_base((unsigned char)arg,
			"0123456789ABCDEF")))
			return (-1);
	}
	else if (data->lmod == 2)
	{
		arg = (long long unsigned int)va_arg(ap, int);
		if (!(data->res = ft_lltoa_base((unsigned short int)arg,
			"0123456789ABCDEF")))
			return (-1);
	}
	return (1);
}
