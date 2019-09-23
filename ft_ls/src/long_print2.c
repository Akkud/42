#include "ft_ls.h"

int				long_print(int tab[4], t_lsfile *file, char date[23])
{
	char	*name;

	if (file->type == 'l'
	&& (!(name = ft_strjoin(file->name, " -> "))
	|| !(name = ft_strlclnjoin(name, file->info->symlink))))
		return (0);
	if (file->type != 'l' && !(name = ft_strdup(file->name)))
		return (0);
	if (file->type == 'c' || file->type == 'b')
	{
		ft_printf("%s %*d %-*s  %-*s  %3u,%4u %5.13s %s\n",
			file->info->aut, tab[0], file->info->hardlink,
			tab[1], file->info->user_name, tab[2], file->info->group_name,
			file->info->major, file->info->minor, date, name);
	}
	else
		ft_printf("%s %*d %-*s  %-*s  %*ld %5.13s %s\n",
			file->info->aut, tab[0], file->info->hardlink,
			tab[1], file->info->user_name, tab[2], file->info->group_name,
			tab[3], file->info->size, date, name);
	ft_strdel(&name);
	return (1);
}

long			ft_total(t_lsfile *file)
{
	long		total;

	total = 0;
	while (!file->end)
	{
		total += file->info->blocks;
		file++;
	}
	return (total);
}

void			ft_print_dir(t_lsfile *file, t_lsdata *data, t_lsfile *parent,
		char total)
{
	int		perm;

	perm = 1;
	if (parent)
		perm = parent->perm;
	if (parent && parent->name && data->type != 3)
		ft_printf("%s:\n", parent->name);
	if (perm && data->display_f == 'l' && total && file && !file->end)
		ft_printf("total %ld\n", ft_total(file));
	if (perm && file && !file->end)
	{
		if (data->display_f == '1')
			ft_single_print(file);
		else if (data->display_f == 'l')
			ft_printl(file, data);
		else if (data->display_f == 'C')
			ft_multi_display(file, data->win_w);
	}
	if (!perm)
	{
		ft_error_handle(data, 1, parent->name, 1);
		display_perm_err(data, parent->name);
	}
}

int				ft_ilen(intmax_t nb)
{
	int		i;

	i = 0;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}
