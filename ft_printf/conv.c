/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:46 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/30 20:02:29 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		(*conv[13]) (va_list ap, t_printf *data);

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
	if (!(data->res = ft_strjoin(tmp,
		ft_ulltoa_base((long long unsigned int)arg, "0123456789abcdef"))))
		return (-1);
	free(tmp);
	if (!data->res)
		return (-1);
	return (0);
}

static int	ft_zeroadd(t_printf *data, char **dec, char **tmp)
{
	char	*zeros;
	
	ft_memdel((void**)tmp);
	if (!(*dec && ft_strlen(*dec) < (size_t)data->pr))
		return (0);
	*tmp = *dec;
	if (!(zeros = ft_strnew(data->pr - ft_strlen(*dec))))
	{
		ft_memdel((void**)dec);
		return (-1);
	}
	ft_memset(zeros, 48, data->pr - ft_strlen(*dec));
	if (!(*dec = ft_strjoin(zeros, *dec)))
	{
		ft_memdel((void**)tmp);
		return (-1);
	}
	ft_memdel((void**)tmp);
	return (1);
}

static int	ft_overfloat(t_printf *data, char **ent, char **dec, int a)
{
	char	*zeros;
	char	*tmp;

	tmp = *dec;
	if (!*ent || !*dec || !(zeros = ft_strnew(data->pr - a)))
	{
		ft_memdel((void**)ent);
		ft_memdel((void**)dec);
		return (-1);
	}
	ft_memset(zeros, 48, data->pr - a);
	if (!(*dec = ft_strjoin(*dec, zeros)))
		ft_memdel((void**)&zeros);
	if ((ft_zeroadd(data, dec, &tmp)) < 0)
			ft_memdel((void**)&zeros);
	if (!(tmp = ft_strjoin(*ent, ".")) || !(data->res = ft_strjoin(tmp, *dec)))
		ft_memdel((void**)&zeros);
	ft_memdel((void**)&tmp);
	ft_memdel((void**)ent);
	ft_memdel((void**)dec);
	if (!zeros)
		return (-1);
	ft_memdel((void**)&zeros);
	return (-1);
}

static int	conv_fltpr(long double arg, t_printf *data, char *dec, char *tmp)
{
	char			*ent;
	int				a;

	a = -1;
	while (++a < data->pr)
		if (((arg - (long long)arg) * ft_power(10, a + 1) + 0.5) <
			((arg - (long long)arg) * ft_power(10, a) + 0.5))
			break ;
	if (!(ent = ft_lltoa(arg)) ||
		!(dec = ft_lltoa((arg - (long long int)arg) * ft_power(10, a) + 0.5)))
		ft_memdel((void*)ent);
//	if (ft_strlen(*dec) < (size_t)data->pr)
//		if (!(dec = ft_zeroadd()))
	printf("a = %d\n", a);
	if (a < data->pr)
		return (ft_overfloat(data, &ent, &dec, a));
	else if (!(tmp = ft_strjoin(ent, ".")) || !(data->res = ft_strjoin(tmp, dec)))
		return (-1);
	ft_memdel((void**)&ent);
	ft_memdel((void**)&dec);
	ft_memdel((void**)&tmp);
	return (-1);
}

static int	conv_fdouble(va_list ap, t_printf *data)
{
	long double		arg;
	char			*dec;
	char			*tmp;

	arg = va_arg(ap, long double);
	dec = NULL;
	tmp = NULL;
	printf("arg = [%Lf]\n", arg);
	if (data->pr == -1)
		data->pr = 6;
	if (data->pr)
		return (conv_fltpr(arg, data, dec, tmp));
	else if (!(data->res = ft_lltoa(arg + 0.5)))
		return (-1);
	printf("realdec = %lld\n", (long long int)((arg - (int)arg) * ft_power(10, data->pr) + 0.5));
	printf("res = %s\n", data->res);
	return (-1);
}

int		conv_main(va_list ap, t_printf *data)
{
	conv[0] = conv_int;
	conv[1] = conv_int;
	conv[2] = conv_octal;
	conv[3] = conv_uint;
	conv[4] = conv_hexalow;
	conv[5] = conv_hexaup;
	conv[6] = conv_uchar;
	conv[7] = conv_char_array;
	conv[8] = conv_pointer;
	conv[9] = conv_fdouble;
//	conv[10] = conv_edouble;
//	conv[11] = conv_gdouble;
//	conv[12] = conv_binary;
	if (((conv[data->conv]) (ap, data)) < 0)
		return (-1);
//	flag_main(data);
	printf("res = [%s]\n", data->res);
	return (0);
}
