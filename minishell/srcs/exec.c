/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:54:41 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:54:42 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_env_tab(t_env *env)
{
	char	**res;
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!(res = ft_memalloc(sizeof(char*) * (i + 1))))
		ft_ex(NULL, "cannot allocate memory\n");
	res[i] = NULL;
	i = 0;
	tmp = env;
	while (tmp)
	{
		if (!(res[i] = ft_strjoin(tmp->name, "="))
		|| !(res[i] = ft_sjoin1(&res[i], tmp->value)))
			ft_ex(NULL, "cannot allocate memory\n");
		tmp = tmp->next;
		i++;
	}
	return (res);
}

void	execution(t_msh *data, char *path)
{
	char	**env;
	int		pid;
	int		status;

	env = make_env_tab(data->env);
	if ((pid = fork()) == -1)
		ft_ex("fork: ", "fatal error");
	if (pid)
		waitpid(pid, &status, WUNTRACED);
	else
	{
		execve(path, data->input, env);
		ft_del_tab((void **)env);
		ft_ex(data->input[0], ": cannot execute the file");
	}
	ft_del_tab((void **)env);
}

int		exec_absolute_path(t_msh *data)
{
	if (ft_isdir(data->input[0]))
		return (-2);
	if (is_file(data->input[0], ft_strrchr(data->input[0], '/')))
	{
		execution(data, data->input[0]);
		return (1);
	}
	return (0);
}

int		exec_path(t_msh *data)
{
	int		i;
	char	**path;
	char	*str;

	i = -1;
	if (!(str = ft_getenv(data->env, "PATH")))
		return (0);
	if (!(path = ft_split(str, ":")))
		ft_ex(NULL, "cannot allocate memory\n");
	while (path[++i])
		if (is_file(path[i], data->input[0]))
		{
			if (!(str = ft_pathjoin(path[i], data->input[0])))
				ft_ex(NULL, "cannot allocate memory\n");
			execution(data, str);
			ft_del_tab((void **)path);
			free(str);
			return (1);
		}
	ft_del_tab((void **)path);
	return (0);
}

int		exec_relative_path(t_msh *data)
{
	char	*pwd;
	char	*path;
	int		ret;

	ret = 0;
	path = NULL;
	if (!(pwd = getcwd(NULL, 0))
	|| !(path = ft_pathjoin(pwd, data->input[0])))
		ft_ex(NULL, "cannot allocate memory\n");
	free(pwd);
	if (ft_isdir(path))
		ret = -2;
	if (!ret && is_file(path, ft_strrchr(path, '/')))
	{
		execution(data, path);
		free(path);
		return (1);
	}
	free(path);
	return (ret);
}
