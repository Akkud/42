/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:46 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/18 17:53:41 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		(*conv[10]) (va_list ap, t_printf *data);

static int	conv_int(va_list ap, t_printf *data)
{
	long long int		arg;

	if (data->lmod == 3)
	{
		arg = (long long int)va_arg(ap, long int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	else 
	{
		arg = (long long int)va_arg(ap, int);
		if (!(data->res = ft_lltoa(arg)))
			return (-1);
	}
	return (0);
}

static int	conv_octal(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	else 
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "01234567")))
			return (-1);
	}
	return (0);
}

static int	conv_uint(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	else 
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789")))
			return (-1);
	}
	return (0);
}

static int	conv_hexalow(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	else 
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789abcdef")))
			return (-1);
	}
	return (0);
}

static int	conv_hexaup(va_list ap, t_printf *data)
{
	long long unsigned int		arg;

	if (data->lmod == 3)
	{
		arg = (long long unsigned int)va_arg(ap, long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	else if (data->lmod == 4)
	{
		arg = va_arg(ap, long long unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	else 
	{
		arg = (long long unsigned int)va_arg(ap, unsigned int);
		if (!(data->res = ft_ulltoa_base(arg, "0123456789ABCDEF")))
			return (-1);
	}
	return (0);
}

static int	conv_uchar(va_list ap, t_printf *data)
{
	unsigned char	arg;

	arg = (unsigned char)va_arg(ap, int);
	if (!(data->res = ft_strnew(1)))
		return (-1);
	data->res[0] = arg;
	return (0);
}

static int	conv_char_array(va_list ap, t_printf *data)
{
	const char		*arg;

	arg = va_arg(ap, const char*);
	if (!(data->res = ft_strdup(arg)))
		return (-1);
	if (data->pr >= 0 && data->pr < (int)ft_strlen(data->res))
		data->res[data->pr] = '\0';
	return (0);
}

static int	conv_pointer(va_list ap, t_printf *data)
{
	void	*arg;
	char	*tmp;

	if (!(tmp = ft_strdup("0x")))
		return (-1);
	arg = va_arg(ap, void*);
	data->res = ft_strjoin(tmp,
				ft_ulltoa_base((long long unsigned int)arg, "0123456789abcdef"));
	free(tmp);
	if (!data->res)
		return (-1);
	return (0);
}

/*
**static int	conv_double(va_list ap, t_printf *data)
**{
**
**}
*/

int		conv_main(va_list ap, t_printf *data)
{
	conv[1] = conv_int;
	conv[2] = conv_int;
	conv[3] = conv_octal;
	conv[4] = conv_uint;
	conv[5] = conv_hexalow;
	conv[6] = conv_hexaup;
	conv[7] = conv_uchar;
	conv[8]	= conv_char_array;
	conv[9]	= conv_pointer;
	if (((conv[data->conv]) (ap, data)) < 0)
		return (-1);
	printf("res = [%s]\n", data->res);
	return (0);
}
