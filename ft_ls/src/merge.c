/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:07:56 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:07:58 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_add_to_s_tab(char **tab, char **s_tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		s_tab[i] = tab[i];
	s_tab[i] = NULL;
}

static int	ft_reverse_merge(char **tab, int l, int m, int r)
{
	int		i;
	int		j;
	int		k;
	char	**l_tab;
	char	**r_tab;

	if (!(l_tab = (char **)malloc(sizeof(char *) * (m - l + 2)))
	|| !(r_tab = (char **)malloc(sizeof(char *) * (r - m + 1))))
		return (0);
	ft_add_to_s_tab((tab + l), l_tab, (m - l + 1));
	ft_add_to_s_tab((tab + m + 1), r_tab, (r - m));
	i = 0;
	j = 0;
	k = l;
	while (i < (m - l + 1) && j < (r - m))
		tab[k++] = (ft_strcmp(l_tab[i], r_tab[j]) > 0)
		? l_tab[i++] : r_tab[j++];
	while (i < (m - l + 1))
		tab[k++] = l_tab[i++];
	while (j < (r - m))
		tab[k++] = r_tab[j++];
	ft_memdel((void **)&l_tab);
	ft_memdel((void **)&r_tab);
	return (1);
}

static int	ft_merge(char **tab, int l, int m, int r)
{
	int		i;
	int		j;
	int		k;
	char	**l_tab;
	char	**r_tab;

	if (!(l_tab = (char **)malloc(sizeof(char *) * (m - l + 2)))
	|| !(r_tab = (char **)malloc(sizeof(char *) * (r - m + 1))))
		return (0);
	ft_add_to_s_tab((tab + l), l_tab, (m - l + 1));
	ft_add_to_s_tab((tab + m + 1), r_tab, (r - m));
	i = 0;
	j = 0;
	k = l;
	while (i < (m - l + 1) && j < (r - m))
		tab[k++] = (ft_strcmp(l_tab[i], r_tab[j]) <= 0)
		? l_tab[i++] : r_tab[j++];
	while (i < (m - l + 1))
		tab[k++] = l_tab[i++];
	while (j < (r - m))
		tab[k++] = r_tab[j++];
	ft_memdel((void **)&l_tab);
	ft_memdel((void **)&r_tab);
	return (1);
}

int			ft_msort(char **tab, int l, int r, int order)
{
	int	m;
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (l < r)
	{
		m = l + (r - l) / 2;
		if (!(ft_msort(tab, l, m, order)) || !(ft_msort(tab, m + 1, r, order)))
			return (0);
		if ((!order && !(ft_merge(tab, l, m, r)))
		|| (order && !(ft_reverse_merge(tab, l, m, r))))
			return (0);
	}
	tab[i] = NULL;
	return (1);
}
