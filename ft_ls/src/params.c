/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:09:02 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:09:04 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			**ft_check_file_access(char **tab, t_lsdata *data,
		int file_n, int i)
{
	struct stat	buf;
	t_lserror	*error;
	char		**res;
	char		**tmp;

	if (!(tmp = (char **)malloc(sizeof(char *) * (file_n + 1)))
	&& !ft_msort(tab, 0, file_n - 1, 0))
		return (NULL);
	res = tmp;
	while (tab[i])
		if (lstat(tab[i], &buf) == -1)
		{
			if (!ft_error_handle(data, 0, tab[i++], 1))
				return (NULL);
			error = data->errors;
			while (error->next)
				error = error->next;
			ft_display_error(data, error);
			error->printed = 1;
		}
		else if (!(*tmp++ = ft_strdup(tab[i++])))
			return (NULL);
	*tmp = NULL;
	ft_clean_str_tab(tab);
	return (res);
}

static int			sort_rev_flag(char **tab, t_lsdata *data)
{
	int		j;

	j = -1;
	while (tab[++j])
		;
	if (!ft_msort(tab, 0, j - 1, data->r))
		return (0);
	return (1);
}

static char			**write_args_to_tab(int ac, char **av, int i,
		t_lsdata *data)
{
	int		j;
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char *) * (ac - i + 1))))
		return (NULL);
	j = 0;
	while (i < ac)
		if (!ft_strlen(av[i]))
		{
			ft_error_handle(data, 3, "fts_open", 1);
			return (NULL);
		}
		else if (!(tab[j++] = ft_strdup(av[i++])))
			return (NULL);
	tab[j] = NULL;
	if (!ft_msort(tab, 0, j - 1, 0))
		return (NULL);
	if (!(tab = ft_check_file_access(tab, data, j, 0)))
		return (NULL);
	return (tab);
}

static t_lsfile		*store_stats_to_file(char **tab, t_lsfile *file,
		t_lsdata *data)
{
	int		j;

	if (!sort_rev_flag(tab, data))
		return (NULL);
	j = -1;
	while (tab[++j])
	{
		ft_file_setup(&(file[j]));
		if (!((file[j]).name = ft_strdup(tab[j]))
		|| !ft_get_file_stats(&(file[j])))
			return (NULL);
	}
	(file[j]).end = 1;
	if (data->t && !(file = ft_sort_time(file, data, j, j)))
		return (NULL);
	ft_clean_str_tab(tab);
	return (file);
}

t_lsfile			*ft_get_params(char **av, int ac, int i, t_lsdata *data)
{
	t_lsfile	*file;
	char		**tab;

	if (i >= ac)
	{
		if (!(file = (t_lsfile *)malloc(sizeof(t_lsfile) * 2)))
			return (NULL);
		ft_file_setup(file);
		if (!(file->name = ft_strdup("."))
		|| !ft_get_file_stats(file))
			return (NULL);
		(file + 1)->end = 1;
	}
	else
	{
		if (!(file = (t_lsfile *)malloc(sizeof(t_lsfile) * (ac - i + 1))))
			return (NULL);
		if (!(tab = write_args_to_tab(ac, av, i, data)))
			return (NULL);
		if (!(file = store_stats_to_file(tab, file, data)))
			return (NULL);
	}
	return (file);
}
