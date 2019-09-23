#include "ft_ls.h"

static int		ft_count_files(char *path, t_lsdata *data)
{
	DIR				*dip;
	struct dirent	*dit;
	int				files;

	files = 0;
	if (!(dip = opendir(path)))
		return (-1);
	while ((dit = readdir(dip)))
		if (data->a || dit->d_name[0] != '.')
			files++;
	if (closedir(dip) == -1)
		return (-1);
	return (files);
}

static int		ft_store_files2(t_lsfile *file, char **tab, char *path)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		ft_file_setup(file);
		if (!(file->name = ft_strdup(tab[i])))
			return (0);
		if (path && !(file->path = ft_strdup(path)))
		{
			free(file->name);
			return (0);
		}
		if (!ft_get_file_stats(file))
		{
			free(file->name);
			free(file->path);
			free(file->info);
			return (0);
		}
		file->end = 0;
		file++;
	}
	file->end = 1;
	return (1);
}

static int		get_file_names(t_lsfile *parent, char **tab, t_lsdata *data)
{
	struct dirent	*dit;
	DIR				*dip;
	int				i;

	if (!(dip = opendir(parent->name)))
		return ((parent->perm = 0) ? -1 : -1);
	i = 0;
	while ((dit = readdir(dip)))
		if ((data->a || dit->d_name[0] != '.')
		&& !(tab[i++] = ft_strdup(dit->d_name)))
			return (-1);
	tab[i] = NULL;
	closedir(dip);
	return (i);
}

t_lsfile		*ft_store_files(t_lsfile *parent, t_lsdata *data)
{
	t_lsfile		*file;
	int				i;
	char			**tab;

	i = ft_count_files(parent->name, data);
	if (!(file = (t_lsfile*)malloc(sizeof(t_lsfile) * (i + 1)))
	|| !(tab = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	if ((i = get_file_names(parent, tab, data)) < 0)
		return (NULL);
	if (!ft_msort(tab, 0, i - 1, data->r)
	|| !ft_store_files2(file, tab, parent->name)
	|| (data->t && !(file = ft_sort_time(file, data, i, i))))
	{
		ft_clean_str_tab(tab);
		free(file);
		return (NULL);
	}
	ft_clean_str_tab(tab);
	return (file);
}
