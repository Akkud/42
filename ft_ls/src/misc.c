/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:08:16 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:08:17 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_clean(t_lsfile *file)
{
	t_lsfile	*tmp;

	tmp = file;
	while (file && !file->end)
	{
		if (file->info)
		{
			free(file->info->symlink);
			file->info->symlink = NULL;
			free(file->info->xattr);
			file->info->xattr = NULL;
			free(file->info->user_name);
			file->info->user_name = NULL;
			free(file->info);
			file->info = NULL;
		}
		free(file->name);
		file->name = NULL;
		free(file->path);
		file->path = NULL;
		file++;
	}
	free(tmp);
}

void	ft_file_setup(t_lsfile *file)
{
	if (file)
	{
		file->name = NULL;
		file->type = 0;
		file->end = 0;
		file->info = NULL;
		file->path = NULL;
		file->perm = 1;
	}
}

void	get_col_lengths(char **tab, int i, int col, int *col_l)
{
	int		j;

	j = 0;
	while (j < col)
	{
		col_l[j] = ft_get_largest_str(tab, i, col, j);
		j++;
	}
}

void	ft_clean_str_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
