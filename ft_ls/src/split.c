/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:09:19 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:09:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		check_dir_perm(t_lsfile *params,
		t_lsfile *dir, t_lsdata *data)
{
	DIR		*dirname;

	if (!(dirname = opendir(params->name)))
	{
		if (!ft_error_handle(data, 1, params->name, 1))
			return (0);
		dir->perm = 0;
	}
	else
	{
		closedir(dirname);
		dir->perm = 1;
	}
	return (1);
}

static int		ft_tab_fill(t_lsfile *file, t_lsfile *dir,
		t_lsfile *params, t_lsdata *data)
{
	while (!params->end)
	{
		if (params->type == 'd')
		{
			if (!ft_file_copy(params, dir))
				return (0);
			if (!check_dir_perm(params, dir, data))
				return (0);
			dir++;
		}
		else if (!ft_file_copy(params, file++))
			return (0);
		params++;
	}
	dir->end = 1;
	file->end = 1;
	return (1);
}

int				ft_tabsplit(t_lsfile **files, t_lsfile **dirs, t_lsdata *data)
{
	t_lsfile	*params;
	t_lsfile	*file;
	int			file_n;
	int			dir_n;

	params = NULL;
	if (data->display_f != 'l' && !(ft_symlink_param(*files)))
		return (0);
	if (*files)
		params = *files;
	dir_n = 0;
	file_n = 0;
	while (!params->end)
		if ((params++)->type == 'd')
			dir_n++;
		else
			file_n++;
	if (!(file = (t_lsfile *)malloc(sizeof(t_lsfile) * (file_n + 1)))
	|| !(*dirs = (t_lsfile *)malloc(sizeof(t_lsfile) * (dir_n + 1))))
		return (0);
	if (!ft_tab_fill(file, *dirs, *files, data))
		return (0);
	ft_clean(*files);
	*files = file;
	return (1);
}
