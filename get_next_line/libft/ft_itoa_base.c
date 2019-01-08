/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:12:56 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 16:48:30 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*get_base(int base)
{
	char	*str;
	int		a;

	a = base - 1;
	if (!(str = ft_memalloc(base + 1)))
		return (0);
	str[base] = '\0';
	base = base - 1;
	while (a > -1)
	{
		if (base > 9)
			str[a] = base + 55;
		else
			str[a] = base + 48;
		a--;
		base--;
	}
	return (str);
}

static int	obou(char *str, char *base)
{
	int a;
	int i;

	a = 0;
	i = 0;
	while (str[a])
	{
		while (str[a] != base[i] && base[i])
			i++;
		if (str[a] == base[i] || str[a] == 45 || str[a] == 43)
			a++;
		else
			break ;
		i = 0;
	}
	return (a);
}

static int	nbr_base(int nbr, char *str, int a, char *base)
{
	int		bl;

	bl = 0;
	while (base[bl])
		bl++;
	if (nbr == 0)
		str[a] = ('0');
	if (nbr < 0)
	{
		str[0] = '-';
		a = 1;
		if (nbr <= bl * (-1))
			a = nbr_base(nbr / bl * (-1), str, a, base);
		str[a] = base[nbr % bl * (-1)];
	}
	if (nbr > 0)
	{
		if (nbr >= bl)
			a = nbr_base(nbr / bl, str, a, base);
		str[a] = base[nbr % bl];
	}
	return (a + 1);
}

char		*ft_itoa_base(int nbr, int base)
{
	char	*res;
	char	*str;
	char	*baseset;

	if (!(baseset = get_base(base)))
		return (0);
	if (!(str = (char*)malloc(33)))
		return (0);
	nbr_base(nbr, str, 0, baseset);
	str[obou(str, baseset)] = '\0';
	if (str[0] == '-' && base != 10)
		str++;
	if (!(res = ft_strdup(str)))
		return (0);
	str[obou(str, baseset)] = '\0';
	return (res);
}
