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

static	int	count_digits(int n)
{
	int		ctr;

	ctr = 0;
	if (n <= 0)
	{
		ctr++;
		n *= -1;
	}
	while (n % 10)
	{
		ctr++;
		n /= 10;
	}
	return (ctr);
}

char		*ft_itoa(int n)
{
	char	*str;

	str = ft_strnew(count_digits(n));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
		str[0] = n + 48;
	return (str);
}
