/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:48:53 by guaubret          #+#    #+#             */
/*   Updated: 2019/07/27 19:16:36 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(intmax_t nbr, char *base)
{
	int		base_l;
	char	*str;

	base_l = ft_strlen(base);
	if (nbr <= -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	if (!(str = ft_strnew(2)))
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		if (!(str = ft_strclnjoin(str, ft_itoa_base(-nbr, base))))
			return (NULL);
		return (str);
	}
	else
	{
		str[0] = base[nbr % base_l];
		if (nbr >= base_l
		&& !(str = ft_strclnjoin(ft_itoa_base((nbr /= base_l), base), str)))
			return (NULL);
		return (str);
	}
}
