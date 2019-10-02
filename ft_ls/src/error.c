/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:07:14 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:07:16 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_perm_err(t_lsdata *data, char *name)
{
	ft_dprintf(2, "%s: %s: Permission denied\n",
	data->prog_name, strip_name(name));
}

void	ft_display_error(t_lsdata *data, t_lserror *error)
{
	if (error->type == 0)
		ft_dprintf(2,
			"%s: %s: No such file or directory\n",
			data->prog_name, error->path);
	else if (error->type == 2)
		ft_dprintf(2,
			"%s: illegal option -- %s\n\
usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n",
			data->prog_name, error->path);
	else if (error->type == 3)
		ft_dprintf(2, "%s: %s: No such file or directory\n",
		data->prog_name, error->path);
}

int		ft_check_dir_perm(t_lsfile *dir, t_lsdata *data)
{
	while (!dir->end)
	{
		if (!opendir(dir->name)
		&& !ft_error_handle(data, 1, dir->name, 2))
			return (0);
		dir++;
	}
	return (1);
}

int		ft_error_dump(t_lsdata *data)
{
	int			exit;
	t_lserror	*error;

	exit = 0;
	error = data->errors;
	while (error)
	{
		if (data->pad && error->type == 1)
		{
			ft_putchar_fd('\n', 2);
			data->pad = 0;
		}
		data->errors = error;
		if (!error->printed)
			ft_display_error(data, error);
		if (error->exit_status > exit)
			exit = error->exit_status;
		free(error->path);
		error = error->next;
		free(data->errors);
	}
	free(data->prog_name);
	free(data);
	return (exit);
}

int		ft_error_handle(t_lsdata *data, int type, char *path, int status)
{
	t_lserror	*tmp;
	t_lserror	*error;

	error = data->errors;
	if (error && type != 3)
	{
		while (error->next)
			error = error->next;
		if (!(tmp = (t_lserror *)malloc(sizeof(t_lserror))))
			return (0);
		error->next = tmp;
	}
	else if (!(tmp = (t_lserror *)malloc(sizeof(t_lserror))))
		return (0);
	tmp->type = type;
	tmp->exit_status = status;
	if (!(tmp->path = ft_strdup(path)))
		return (0);
	tmp->printed = (type == 1) ? 1 : 0;
	tmp->next = NULL;
	data->errors = (error && type != 3) ? data->errors : tmp;
	return (1);
}
