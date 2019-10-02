/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:07:48 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:07:50 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		folder_rec_main(t_lsfile *file, t_lsfile *dirs, t_lsdata *data)
{
	t_lsfile *tmp;

	data->type = 1;
	tmp = dirs;
	ft_clean(file);
	if (!(file = ft_store_files(dirs, data)))
		return ;
	if (data->param_nb < 2 && data->rr)
		ft_ls(file, data, dirs, 0);
	else
		ft_ls(file, data, dirs, 1);
	dirs++;
	while (!dirs->end)
	{
		if (dirs->perm && !(file = ft_store_files(dirs, data)))
			return ;
		ft_printf("\n");
		if (!(ft_ls(file, data, dirs, 1)))
			return ;
		dirs++;
	}
	ft_clean(tmp);
}

static void		file_main(t_lsfile *file, t_lsfile *dirs, t_lsdata *data)
{
	t_lsfile	*tmp;

	data->type = 2;
	tmp = dirs;
	ft_print_dir(file, data, NULL, 0);
	ft_clean(file);
	if (dirs->end)
		data->pad = 1;
	while (!dirs->end)
	{
		if (!(file = ft_store_files(dirs, data)))
			return ;
		ft_printf("\n");
		ft_ls(file, data, dirs, 1);
		dirs++;
	}
	ft_clean(tmp);
}

static void		folder_main(t_lsfile *file, t_lsfile *dirs, t_lsdata *data)
{
	data->type = 3;
	ft_clean(file);
	if (dirs->perm && !(file = ft_store_files(dirs, data)))
		return ;
	ft_print_dir(file, data, dirs, 1);
	if (dirs->perm)
		ft_clean(file);
	ft_clean(dirs);
}

int				main(int ac, char **av)
{
	t_lsfile		*file;
	t_lsfile		*dirs;
	t_lsdata		*data;
	int				i;
	struct winsize	ws;

	if (((i = get_options(av, ac, &data)) < 0)
	|| !(file = ft_get_params(av, ac, i, data))
	|| !ft_tabsplit(&file, &dirs, data))
		return (ft_error_dump(data));
	data->param_nb = ac - i;
	ioctl(1, TIOCGWINSZ, &ws);
	data->win_w = ws.ws_col;
	if (file->end && !dirs->end
	&& (data->rr || !(dirs + 1)->end || data->param_nb > 1))
		folder_rec_main(file, dirs, data);
	else if (!file->end)
		file_main(file, dirs, data);
	else if (!dirs->end && (dirs + 1)->end && file->end)
		folder_main(file, dirs, data);
	return (ft_error_dump(data));
}
