/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:11:16 by guaubret          #+#    #+#             */
/*   Updated: 2019/01/14 17:19:42 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_write_piece(char ***square, t_tetris *piece)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	square[0][piece->pos[0]][piece->pos[1]] = piece->value;
	while (++i < 3)
	{
		y = piece->pos[0] + piece->bloc[i][0];
		x = piece->pos[1] + piece->bloc[i][1];
		square[0][y][x] = piece->value;
	}
}

void		ft_clear_piece(char ***square, int dim, char letter)
{
	int		x;
	int		y;

	y = -1;
	while (++y < dim)
	{
		x = -1;
		while (++x < dim)
			if (square[0][y][x] == letter)
				square[0][y][x] = '.';
	}
}

int			ft_enlarge_dim(char ***square, int *dim)
{
	ft_free_square(square, *dim);
	*dim += 1;
	if (!(ft_init_square(square, *dim)))
		return (0);
	return (1);
}

void		ft_print_square(char **square, int dim)
{
	int		i;
	int		j;

	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
			ft_putchar(square[i][j]);
		ft_putchar('\n');
	}
}

int			ft_init_square(char ***square, int dim)
{
	int		i;
	int		j;

	i = -1;
	if (!(square[0] = (char**)malloc(dim * sizeof(char*))))
		return (0);
	while (++i < dim)
		if (!(square[0][i] = (char*)malloc(dim)))
			return (0);
	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
			square[0][i][j] = '.';
	}
	return (1);
}
