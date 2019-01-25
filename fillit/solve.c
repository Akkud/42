/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:07:30 by pacharbo          #+#    #+#             */
/*   Updated: 2019/01/14 17:19:38 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_find_blocs(char **tab, int bloc[3][2])
{
	int	y;
	int	x;
	int	i;
	int	pos[2];

	y = -1;
	i = -1;
	while (++y < 4)
	{
		x = -1;
		while (tab[y][++x])
			if (tab[y][x] == '#')
			{
				if (++i > 0)
				{
					bloc[i - 1][0] = y - pos[0];
					bloc[i - 1][1] = x - pos[1];
				}
				else
				{
					pos[0] = y;
					pos[1] = x;
				}
			}
	}
}

static t_tetris	*ft_next_pos(t_tetris *piece, int dim)
{
	if (piece->pos[1] + piece->xmax >= dim - 1)
	{
		piece->pos[1] = 0;
		piece->pos[0]++;
	}
	else
		piece->pos[1]++;
	return (piece);
}

static int		ft_find_pos(char **square, int dim, t_tetris *piece)
{
	while (!(piece->pos[0] + piece->bloc[2][0] >= dim))
	{
		if (check_place(square, dim, piece->pos, piece->bloc))
			return (1);
		ft_next_pos(piece, dim);
	}
	piece->pos[0] = 0;
	piece->pos[1] = 0;
	return (0);
}

static void		solve_rec(char ***square, t_tetris *piece, int dim, int *check)
{
	int	ret;

	ft_move_to_dup(*square, dim, piece);
	ret = ft_find_pos(*square, dim, piece);
	while (ret)
	{
		ft_write_piece(square, piece);
		if (piece->next == NULL)
			*check = 1;
		else
			solve_rec(square, piece->next, dim, check);
		if (!*check)
		{
			ft_clear_piece(square, dim, piece->value);
			ret = ft_find_pos(*square, dim, ft_next_pos(piece, dim));
		}
		else
			return ;
	}
	ft_clear_piece(square, dim, piece->value);
}

int				ft_solve_main(char ***square, t_tetris *list, int dim)
{
	int check;

	check = 0;
	while (!check)
	{
		solve_rec(square, list, dim, &check);
		if (!check && !ft_enlarge_dim(square, &dim))
			return (0);
	}
	ft_print_square(*square, dim);
	return (1);
}
