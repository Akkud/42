/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:46 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/08 17:33:26 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	conv_int(va_list ap, t_printf *data)
{
	if(!(data->res = ft_itoa_base))
//		exit();
	

}

static int	conv_octal(va_list ap, t_printf *data)
{
	
}

static int	conv_uint(va_list ap, t_printf *data)
{
	
}

static int	conv_hexa(va_list ap, t_printf *data)
{
	
}

static int	conv_uchar(va_list ap, t_printf *data)
{
	
}

static int	conv_char_array(va_list ap, t_printf *data)
{
	
}

static int	conv_pointer(va_list ap, t_printf *data)
{
	
}

/*
**static int	conv_double(va_list ap, t_printf *data)
**{
**
**}
*/

static int		conv_main(va_list ap, t_printf data)
{
	conv[1] = conv_int;
	conv[2] = conv_int;
	conv[3] = conv_octal;
	conv[4] = conv_uint;
	conv[5] = conv_hexa;
	conv[6] = conv_hexa;
	conv[7] = conv_uchar;
	conv[8]	= conv_char_array;
	conv[9]	= conv_pointer;
	if (!((conv[data->conv]) (ap, data)))
		return (0);
	return (1);
}
