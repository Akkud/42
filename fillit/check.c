/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:23:19 by guaubret          #+#    #+#             */
/*   Updated: 2019/01/25 19:17:06 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_line(char *line, int i)
{
	if (i % 5 == 0 && ft_strlen(line))
		return (0);
	else if (i % 5 != 0)
	{
		if (ft_strlen(line) != 4)
			return (0);
		line--;
		while (*++line)
			if (*line != '.' && *line != '#')
				return (0);
	}
	return (1);
}

static int	ft_check_sharps(char **tab, int x, int y)
{
	int		ret;

	ret = 0;
	if (x != 3 && tab[y][x + 1] == '#')
		ret++;
	if (x != 0 && tab[y][x - 1] == '#')
		ret++;
	if ((y + 1) % 5 != 4 && tab[y + 1][x] == '#')
		ret++;
	if ((y + 1) % 5 != 1 && tab[y - 1][x] == '#')
		ret++;
	return (ret);
}

int			ft_check_pieces(char **tab, int y)
{
	int		sharps;
	int		contacts;
	int		x;

	sharps = 0;
	contacts = 0;
	while (tab[++y])
	{
		x = -1;
		while (++x < 4 && ft_strlen(tab[y]))
			if (tab[y][x] == '#')
			{
				sharps++;
				contacts += ft_check_sharps(tab, x, y);
			}
		if (!((y + 2) % 5))
		{
			if (sharps != 4 || (contacts != 6 && contacts != 8))
				return (0);
			sharps = 0;
			contacts = 0;
		}
	}
	return (1);
}

int			check_place(char **square, int dim, int pos[2], int bloc[3][2])
{
	int		i;
	int		x;
	int		y;

	i = -1;
	if (square[pos[0]][pos[1]] != '.')
		return (0);
	while (++i < 3)
	{
		y = pos[0] + bloc[i][0];
		x = pos[1] + bloc[i][1];
		if (y < 0 || y >= dim || x < 0 || x >= dim
				|| square[y][x] != '.')
			return (0);
	}
	return (1);
}
