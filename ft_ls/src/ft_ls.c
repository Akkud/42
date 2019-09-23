#include "ft_ls.h"

static int		check_dirs(t_lsfile *file)
{
	int		cnt;

	cnt = 0;
	while (!file->end)
	{
		if (file->type == 'd'
		&& !(ft_strcmp(file->name, ".") == 0
		|| ft_strcmp(file->name, "..") == 0))
			cnt++;
		file++;
	}
	return (cnt);
}

t_lsfile		*ft_store_dirs(t_lsfile *file)
{
	t_lsfile	*dirs;
	int			i;
	DIR			*dirname;

	i = check_dirs(file);
	if (!(dirs = (t_lsfile *)malloc(sizeof(t_lsfile) * (i + 1))))
		return (0);
	i = 0;
	while (!file->end)
	{
		if (!(ft_strcmp(file->name, ".") == 0
		|| ft_strcmp(file->name, "..") == 0) && file->type == 'd')
		{
			if (!ft_file_copy(file, &dirs[i])
			|| !(join_file_names(file->path, file->name, &(dirs[i].name))))
				return (0);
			if ((dirname = opendir(dirs[i].name)))
				closedir(dirname);
			dirs[i].perm = dirname ? 1 : 0;
			i++;
		}
		file++;
	}
	dirs[i].end = 1;
	return (dirs);
}

int				ft_ls(t_lsfile *dirs_file, t_lsdata *data, t_lsfile *parent,
char dir)
{
	t_lsfile	*dirs;
	t_lsfile	*file;
	t_lsfile	*dirtmp;

	dir ? ft_print_dir(dirs_file, data, parent, 1)
		: ft_print_dir(dirs_file, data, NULL, 1);
	if (data->rr && parent->perm)
	{
		if (!(dirs = ft_store_dirs(dirs_file)))
			return (0);
		dirtmp = dirs;
		while (!dirs->end)
		{
			if (!dirs->perm || (file = ft_store_files(dirs, data)))
			{
				ft_printf("\n");
				ft_ls(file, data, dirs, 1);
			}
			dirs++;
		}
		ft_clean(dirtmp);
	}
	if (parent->perm && dirs_file)
		ft_clean(dirs_file);
	return (1);
}
