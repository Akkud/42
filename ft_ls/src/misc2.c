/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:08:44 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:08:45 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsfile		*ft_sort_time(t_lsfile *file, t_lsdata *data, int i, int j)
{
	t_lsfile	*res;
	long		*tab;
	t_lsfile	*tmp;

	if (!(tab = (long*)malloc(sizeof(long) * (i + 1)))
	|| !(res = (t_lsfile*)malloc(sizeof(t_lsfile) * (i + 1))))
		return (0);
	i = -1;
	while (!(file[++i]).end)
		tab[i] = (file[i]).info->date;
	ft_nmsort((long long*)tab, 0, i - 1, data->r);
	tmp = file;
	i = -1;
	while (++i < j && (file = tmp))
		while (!(file)->end)
			if (tab[i] == (file++)->info->date && (file - 1)->name)
			{
				res[i] = *(file - 1);
				(file - 1)->name = NULL;
				break ;
			}
	(res[i]).end = 1;
	free(tmp);
	free(tab);
	return (res);
}

static int		ft_info_copy(t_lsfilestat *param, t_lsfilestat *file)
{
	int		i;

	i = -1;
	file->symlink = NULL;
	if (!ft_strcpy(file->aut, param->aut))
		return (0);
	if (param->user_name
	&& !(file->user_name = ft_strdup(param->user_name)))
		return (0);
	if (param->group_name)
		file->group_name = param->group_name;
	if ((param->symlink && !(file->symlink = ft_strdup(param->symlink))))
		return (0);
	file->xattr = param->xattr;
	param->xattr = NULL;
	file->hardlink = param->hardlink;
	file->blocks = param->blocks;
	file->date = param->date;
	file->size = param->size;
	file->major = param->major;
	file->minor = param->minor;
	file->xattr_size = param->xattr_size;
	return (1);
}

int				ft_file_copy(t_lsfile *param, t_lsfile *file)
{
	if (!param || !file)
		return (0);
	ft_file_setup(file);
	if (param->name && !(file->name = ft_strdup(param->name)))
		return (0);
	if (param->path && !(file->path = ft_strdup(param->path)))
		return (0);
	file->type = param->type;
	if (param->info)
	{
		if (!(file->info = (t_lsfilestat *)malloc(sizeof(t_lsfilestat))))
			return (0);
		if (!ft_info_copy(param->info, file->info))
			return (0);
	}
	return (1);
}

int				get_xattr(t_lsfilestat *info, char *path)
{
	if ((info->xattr_size = listxattr(path, NULL, 0, XATTR_NOFOLLOW)) < 1)
		return (1);
	info->aut[10] = '@';
	if (!(info->xattr = (char *)malloc(info->xattr_size)))
		return (0);
	listxattr(path, info->xattr, info->xattr_size, XATTR_NOFOLLOW);
	return (1);
}
