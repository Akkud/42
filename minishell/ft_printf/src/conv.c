/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:46 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:04:25 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		conv_uchar(va_list ap, t_printf *data)
{
	unsigned char	arg;

	arg = (unsigned char)va_arg(ap, int);
	if (!(data->res = ft_strnew(1)))
		return (-1);
	data->res[0] = arg;
	return (1);
}

int		conv_char_array(va_list ap, t_printf *data)
{
	const char		*arg;

	arg = va_arg(ap, const char*);
	if (!arg)
	{
		if (!(data->res = ft_strdup("(null)")))
			return (-1);
		return (1);
	}
	if (!(data->res = ft_strdup(arg)))
		return (-1);
	if (data->pr >= 0 && data->pr < (int)ft_strlen(data->res))
		data->res[data->pr] = '\0';
	return (1);
}

int		conv_pointer(va_list ap, t_printf *data)
{
	void	*arg;
	char	*tmp;

	if (!(tmp = ft_strdup("0x")))
		return (-1);
	arg = va_arg(ap, void*);
	data->res = ft_ulltoa_base((long long unsigned int)arg, "0123456789abcdef");
	if (!(data->res = ft_sjoin3(&tmp,
		&data->res)))
		return (-1);
	free(tmp);
	return (1);
}

int		conv_binary(va_list ap, t_printf *data)
{
	void	*arg;

	arg = va_arg(ap, void*);
	if (!(data->res = ft_ulltoa_base((long long unsigned int)arg, "01")))
		return (-1);
	return (1);
}

int		conv_percent(va_list ap, t_printf *data)
{
	(void)ap;
	if (!(data->res = ft_strdup("%")))
		return (-1);
	return (1);
}
