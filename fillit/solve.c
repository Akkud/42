/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:07:30 by pacharbo          #+#    #+#             */
/*   Updated: 2019/01/10 20:29:21 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_free_list(t_tetris **list)
{
	t_tetris	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

static void		ft_print_square(char **square, int dim)
{
	int	i;
	int	j;

	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
			ft_putchar(square[i][j]);
		ft_putchar('\n');
	}
}

static int		ft_enlarge_dim(char ***square, int *dim)
{
	ft_free_square(square, *dim);
	*dim += 1;
	if (!(ft_init_square(square, *dim)))
		return (0);
	return (1);
}

int				check_place(char **square, int dim, int pos[2], int bloc[3][2])
{
	int	i;
	int	x;
	int	y;

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

static void		ft_write_piece(char ***square, t_tetris *piece)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	square[0][piece->pos[0]][piece->pos[1]] = piece->value;
	while (++i < 3)
	{
		y = piece->pos[0] + piece->bloc[i][0];
		x = piece->pos[1] + piece->bloc[i][1];
		square[0][y][x] = piece->value;
	}
}

static void		ft_clear_piece(char ***square, int dim, char letter)
{
	int	x;
	int	y;

	y = -1;
	while (++y < dim)
	{
		x = -1;
		while (++x < dim)
			if (square[0][y][x] == letter)
				square[0][y][x] = '.';
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

static void		ft_move_to_dup(char **square, int dim, t_tetris *piece)
{
	int	x;
	int	y;

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

int				ft_init_square(char ***square, int dim)
{
	int	i;
	int	j;

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
