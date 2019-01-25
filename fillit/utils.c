/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:01:40 by guaubret          #+#    #+#             */
/*   Updated: 2019/01/25 20:11:38 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	bloc_assign(int *i, int pos[3][2], t_tetris *new)
{
	if (pos[*i][1] > new->xmax)
		new->xmax = pos[*i][1];
	new->bloc[*i][0] = pos[*i][0];
	new->bloc[*i][1] = pos[*i][1];
	(*i)++;
}

int		ft_sqrt_up(int x)
{
	int		i;

	i = 0;
	while (i * i < x)
		i++;
	return (i);
}

void	ft_move_to_dup(char **square, int dim, t_tetris *piece)
{
	int		x;
	int		y;

	y = -1;
	if (piece->duplicate)
		while (++y < dim)
		{
			x = -1;
			while (++x < dim)
				if (square[y][x] == piece->duplicate)
				{
					piece->pos[0] = y;
					piece->pos[1] = x;
					return ;
				}
		}
}

int		check_fd(char *file)
{
	int		fd;
	char	buf[1001];
	int		ret;

	if ((fd = open(file, O_DIRECTORY) >= 0))
		return (-1);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	if ((ret = read(fd, buf, 1000)) > 0)
		buf[ret] = 0;
	if (ret <= 0 || buf[ret - 1] != '\n')
	{
		close(fd);
		return (-1);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	return (fd);
}
