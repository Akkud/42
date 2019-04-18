/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:47:30 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/09 19:14:30 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_ulltoa_base(unsigned long long nb, char *base)
{
	int			a;
	int			b;
	int			i;
	unsigned long long	tmp;
	char		*res;

	a = 1;
	if (nb < ft_strlen(base))
		a = 0;
	i = 0;
	tmp = nb;
	while ((tmp /= ft_strlen(base)) >= (unsigned long long)ft_strlen(base))
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
