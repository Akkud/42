/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:47:30 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/09 19:39:19 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*neg(long long nb, char *base)
{
	int			a;
	int			b;
	int			i;
	long long	tmp;
	char		*res;

	a = nb > (int)ft_strlen(base) ?  0 : 1;
	i = 0;
	tmp = nb;
	while ((tmp /= (int)ft_strlen(base)) <= ((long long)ft_strlen(base) * -1))
		a++;
	if (!(res = ft_strnew(a + 2)))
		return (0);
	res[i++] = '-';
	while (a-- >= 0)
	{
		b = 0;
		tmp = nb;
		while (b++ <= a)
			tmp /= (int)ft_strlen(base);
		res[i++] = base[-tmp % (int)ft_strlen(base)];
	}
	return (res);
}

char		*ft_lltoa_base(long long nb, char *base)
{
	int			a;
	int			b;
	int			i;
	long long	tmp;
	char		*res;

	if (nb < 0)
		return (neg(nb, base));
	a = nb < (int)ft_strlen(base) ?  0 : 1;
	i = 0;
	tmp = nb;
	while ((tmp /= ft_strlen(base)) >= (long long)ft_strlen(base))
		a++;
	if (!(res = ft_strnew(a + 1)))
		return (0);
	while (a-- >= 0)
	{
		b = 0;
		tmp = nb;
		while (b++ <= a)
			tmp /= ft_strlen(base);
		res[i++] = base[tmp % ft_strlen(base)];
	}
	return (res);
}
