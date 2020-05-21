/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:53:37 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 08:15:41 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			display_cd_errors(char *error)
{
	if (!(error))
		exit(EXIT_FAILURE);
	ft_err("cd: ", error);
	free(error);
	return (1);
}

int			check_enametoolong(char *path)
{
	int		i;
	char	*buf;

	i = 2;
	if (ft_strlen(path) >= 1024)
		return (0);
	while ((buf = ft_strcut(path, "/", i)))
	{
		if (ft_strlen(buf) >= 1024)
		{
			free(buf);
			return (0);
		}
		if (!*buf)
		{
			free(buf);
			break ;
		}
		free(buf);
		i++;
	}
	return (1);
}

int			check_chdir_errors(char **error, char *path, char *opr)
{
	int ret;

	ret = 0;
	if (!check_enametoolong(path))
	{
		*error = (ft_strjoin(opr, ": File name too long"));
		return (1);
	}
	ret = check_whole_path(path);
	if (ret == 1)
		*error = (ft_strjoin(opr, ": No such file or directory"));
	if (ret == 2)
		*error = (ft_strjoin(opr, ": Symbolic link error"));
	if (ret == 3)
		*error = (ft_strjoin(opr, ": Not a directory"));
	if (ret == 4)
		*error = (ft_strjoin(opr, ": Permission denied"));
	if (!ret)
		return (0);
	return (1);
}
