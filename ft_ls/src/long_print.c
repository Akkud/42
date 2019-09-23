#include "ft_ls.h"

static void		ft_get_largest_by_field(t_lsfile *file, int tab[4])
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	while (!file->end)
	{
		tab[0] = (tab[0] < ft_ilen((intmax_t)file->info->hardlink))
		? (int)ft_ilen((intmax_t)file->info->hardlink) : tab[0];
		tab[1] = (tab[1] < (int)ft_strlen(file->info->user_name))
		? (int)ft_strlen(file->info->user_name) : tab[1];
		tab[2] = (tab[2] < (int)ft_strlen(file->info->group_name))
		? (int)ft_strlen(file->info->group_name) : tab[2];
		if (file->type == 'c' || file->type == 'b')
			tab[3] = (tab[3] < 8) ? 8 : tab[3];
		else
			tab[3] = (tab[3] < ft_ilen((intmax_t)file->info->size))
		? (int)ft_ilen((intmax_t)file->info->size) : tab[3];
		file++;
	}
}

static void		ft_strdatecat(char *s1, char *s2)
{
	int a;

	a = 0;
	while (*s1)
		s1++;
	while (*s2 == ' ')
		s2++;
	*s1++ = ' ';
	while (*s2 >= '0' && *s2 <= '9')
		*s1++ = *s2++;
	*s1 = '\0';
}

static void		get_date_string(t_lsfile *file, char date[23])
{
	time_t	tmp;
	char	cur_str[26];
	char	cur_time[10];
	char	file_time[10];

	tmp = time(&tmp);
	ft_strcpy(cur_str, ctime(&tmp));
	ft_strcpy(cur_time, ctime(&tmp) + 20);
	ft_strcpy(file_time, ctime(&file->info->date) + 20);
	if (ft_strncmp(file_time, cur_time, 5) != 0
	|| tmp < file->info->date
	|| tmp > file->info->date + 15768000)
	{
		ft_strncpy(date, ctime(&file->info->date) + 4, 7);
		date[7] = '\0';
		ft_strdatecat(date, ctime(&file->info->date) + 19);
	}
	else
	{
		ft_strcpy(date, ctime(&file->info->date) + 4);
		date[12] = '\0';
	}
}

static int		ft_print_xattr(t_lsfile *file)
{
	char		*tmp;
	char		*path;
	ssize_t		size1;
	ssize_t		size2;

	size1 = file->info->xattr_size;
	tmp = file->info->xattr;
	if (file->path && !(path = ft_strjoin(file->path, file->name)))
		return (0);
	else if (!file->path && !(path = ft_strdup(file->name)))
		return (0);
	while (size1 > 0)
	{
		size2 = getxattr(path, tmp, NULL, 0, 0, XATTR_NOFOLLOW);
		if (size2 < 0)
		{
			free(path);
			return (0);
		}
		ft_printf("\t%s\t%2d\n", tmp, size2);
		size1 -= ft_strlen(tmp) + 1;
		tmp += ft_strlen(tmp) + 1;
	}
	free(path);
	return (1);
}

int				ft_printl(t_lsfile *file, t_lsdata *data)
{
	int		tab[4];
	char	date[23];

	ft_get_largest_by_field(file, tab);
	while (!file->end)
	{
		get_date_string(file, date);
		if (!long_print(tab, file, date))
			return (0);
		if (data->at && file->info->xattr && !ft_print_xattr(file))
			return (0);
		file++;
	}
	return (1);
}
