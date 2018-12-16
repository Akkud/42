/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:51:32 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/13 19:08:50 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checki_breeki(char **tab)
{
	int y;

	y = 0;
	while (tab[y])
	{
		if (!((y + 1) % 5) && tab[y][0])
			return (0);
		if ((y + 1) % 5 && ft_strlen(tab[y]) != 4)
			return (0);
		if (!tab[y + 1] && (y + 1) % 5 != 4)
			return (0);
		y++;
	}
	y = 0;
	while (tab[y])
	{
		if ((y + 1) % 5 == 1)
			if (!check_tetrucs(tab + y))
				return (0);
		y++;
	}
	return (1);
}

int		check_sharps(char **tab, int x, int y)
{
	int	a;

	a = 0;
	if (x != 3)
		if (tab[y][x + 1] == '#')
			a++;
	if (x != 0)
		if (tab[y][x - 1] == '#')
			a++;
	if (y != 3)
		if (tab[y + 1][x] == '#')
			a++;
	if (y != 0)
		if (tab[y - 1][x] == '#')
			a++;
	return (a);
}

int		check_tetrucs(char **tab)
{
	int a;
	int b;
	int x;
	int y;

	y = 0;
	a = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] == '#')
				a++;
			b += check_sharps(tab, x, y);
			x++;
		}
		y++;
	}
	if (a != 4 || b < 6)
		return (0);
	return (1);
}
