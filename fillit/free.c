/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:39:43 by guaubret          #+#    #+#             */
/*   Updated: 2019/01/14 16:43:20 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_list(t_tetris **list)
{
	t_tetris	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

void	ft_free_square(char ***square, int dim)
{
	int		i;

	i = -1;
	while (++i < dim)
		free(square[0][i]);
	free(square[0]);
}

void	ft_free_tab(char ***tab)
{
	char	**ptr;

	ptr = *tab;
	while (*ptr)
		ft_strdel(&(*ptr++));
	if (*tab)
		free(*tab);
}
