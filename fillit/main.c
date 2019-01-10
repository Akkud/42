/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:55:47 by pacharbo          #+#    #+#             */
/*   Updated: 2019/01/10 19:43:45 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_free_square(char ***square, int dim)
{
	int	i;

	i = -1;
	while (++i < dim)
		free(square[0][i]);
	free(square[0]);
}

void			ft_print_words_tables(char **tab)
{
	while (*tab)
		ft_putendl(*tab++);
}

static int		ft_error(int error, t_tetris **list, char ***tab)
{
	if (list && *list)
		ft_free_list(list);
	if (tab && *tab)
		ft_free_tab(tab);
	if (error == 1)
		ft_putendl("error");
	if (error == 2)
		ft_putendl("usage: ./fillit target_file");
	return (0);
}

int				main(int ac, char **av)
{
	char		**tab;
	t_tetris	*list;
	char		**square;
	int			dim;

	if (ac != 2)
		return (ft_error(2, NULL, NULL));
	if (!(read_main(av[1], &tab, &dim)))
		return (ft_error(1, NULL, &tab));
	if (!(list = ft_store_piece(tab, 0, 0, 0)))
		return (ft_error(1, &list, &tab));
	if (!ft_init_square(&square, dim))
	{
		ft_free_square(&square, dim);
		return (ft_error(1, &list, &tab));
	}
	if (!ft_solve_main(&square, list, dim))
	{
		ft_free_square(&square, dim);
		return (ft_error(1, &list, &tab));
	}
	ft_free_list(&list);
	ft_free_tab(&tab);
	ft_free_square(&square, dim);
	return (0);
}
