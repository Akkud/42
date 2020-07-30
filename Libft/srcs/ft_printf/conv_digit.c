/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:05:59 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 07:00:23 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_int(va_list ap, t_printf *data)
{
	long long int		arg;

	if (data->lmod == 3)
	{
		arg = (long long int)va_arg(ap, long int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	else if (data->lmod == 4 || data->lmod == 5)
	{
		arg = va_arg(ap, long long int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	else if (data->lmod)
		return (conv_int2(ap, data));
	else
	{
		arg = (long long int)va_arg(ap, int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	return (1);
}

int		conv_octal(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	else if (data->lmod == 4 || data->lmod == 5)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	else if (data->lmod)
		return (conv_octal2(ap, data));
	else
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	return (1);
}

int		conv_uint(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	else if (data->lmod == 4 || data->lmod == 5)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	else if (data->lmod)
		return (conv_uint2(ap, data));
	else
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	return (1);
}

int		conv_hexalow(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	else if (data->lmod == 4 || data->lmod == 5)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	else if (data->lmod)
		return (conv_hexalow2(ap, data));
	else
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	return (1);
}

int		conv_hexaup(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	else if (data->lmod == 4 || data->lmod == 5)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	else if (data->lmod)
		return (conv_hexaup2(ap, data));
	else
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	return (1);
}
