/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:56:22 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:58:17 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_file(char *path, char *str)
{
	DIR				*dir;
	struct dirent	*dit;
	int				ret;
	char			*name;

	ret = 0;
	if (!*str)
		return (0);
	if (*str == '/')
		*str = '\0';
	name = *str ? str : str + 1;
	if (!(dir = opendir(path)))
	{
		*str = *str ? *str : '/';
		return (0);
	}
	while (!ret && (dit = readdir(dir)))
		if (!ft_strcmp(dit->d_name, name))
			ret = 1;
	closedir(dir);
	*str = *str ? *str : '/';
	return (ret);
}

void	ft_ex(char *str1, char *error)
{
	ft_putstr_fd("minishell: ", 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

int		ft_err(char *str1, char *error)
{
	ft_putstr_fd("minishell: ", 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	ft_putendl_fd(error, 2);
	return (-1);
}

void	free_memory(t_msh *data)
{
	ft_strdel(&data->cwd);
	ft_del_tab((void**)data->input);
}
