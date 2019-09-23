/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:33:03 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/12 22:14:44 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;

	str = NULL;
	if (n == -2147483648)
	{
		if (!(str = ft_strnew(12)))
			return (NULL);
		return (ft_strcpy(str, "-2147483648"));
	}
	if (n < 0 && (!(str = ft_strnew(1))
	|| (!(str = ft_strclnjoin(ft_strcpy(str, "-"), ft_itoa(-n))))))
		return (NULL);
	else if (n >= 10
	&& !(str = ft_strclnjoin(ft_itoa(n / 10), ft_itoa(n % 10))))
		return (NULL);
	else if (n < 10 && n >= 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = n + 48;
		str[1] = 0;
	}
	return (str);
}
