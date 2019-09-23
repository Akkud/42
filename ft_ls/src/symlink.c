#include "ft_ls.h"

static int		ft_get_symlink_path(char *name, char **path)
{
	char	*tmp;
	char	*ret;

	if (!(ft_strrchr(name, '/')))
	{
		*path = NULL;
		return (1);
	}
	if (!(ret = ft_strdup(name)))
		return (0);
	tmp = ft_strrchr(ret, '/');
	if (tmp)
		*(tmp + 1) = 0;
	*path = ret;
	return (1);
}

static int		symlink_solve(t_lsfile *tmp, t_lsfile *file)
{
	tmp->name = ft_strdup(file->info->symlink);
	if (!tmp->name || (tmp->name[0] != '/'
	&& !ft_get_symlink_path(file->name, &(tmp->path)))
	|| !ft_get_file_stats(tmp))
		return (0);
	tmp->name = ft_strdup(file->name);
	if (tmp->name && tmp->type == 'd')
	{
		ft_file_copy(tmp, file);
		file->type = 'd';
	}
	return (1);
}

int				ft_symlink_param(t_lsfile *file)
{
	t_lsfile	*tmp;
	struct stat	buf;

	tmp = NULL;
	while (!file->end)
	{
		if (file->type == 'l')
		{
			if (!(tmp = (t_lsfile*)malloc(sizeof(t_lsfile) * 2)))
				return (0);
			ft_file_setup(tmp);
			(tmp + 1)->end = 1;
			if (stat(file->name, &buf) > -1)
				if (!symlink_solve(tmp, file))
					return (0);
			ft_clean(tmp);
		}
		file++;
	}
	return (1);
}
