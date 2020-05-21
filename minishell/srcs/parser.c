/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:56:15 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:58:35 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_assign(t_msh *data)
{
	char	*name;
	char	*equal;
	char	*value;

	if (data->input[1] || !(equal = ft_strchr(data->input[0], '=')))
		return (0);
	name = data->input[0];
	*equal = '\0';
	if (!ft_isname(name))
	{
		*equal = '=';
		return (0);
	}
	if (!(value = ft_strdup(equal + 1)))
		ft_ex(NULL, "cannot allocate memory");
	exp_main(data, &value, 1);
	ft_setenv(data->env, name, value);
	*equal = '=';
	free(value);
	return (1);
}

int		builtin_call(t_msh *data)
{
	if (!ft_strcmp("cd", data->input[0]))
		ft_cd(data->input + 1, data);
	else if (!ft_strcmp("echo", data->input[0]))
		ft_echo(data->input + 1);
	else if (!ft_strcmp("env", data->input[0]))
		ft_env(data);
	else if (!ft_strcmp("setenv", data->input[0]))
	{
		if (!data->input[1])
			return (ft_err(NULL, "Error.\nUsage: setenv [name] [value]"));
		ft_setenv(data->env, data->input[1], data->input[2]);
	}
	else if (!ft_strcmp("unsetenv", data->input[0]))
	{
		if (!data->input[1])
			return (ft_err(NULL, "Error.\nUsage: unsetenv [name]"));
		ft_unsetenv(data, data->input[1]);
	}
	else if (!ft_strcmp("exit", data->input[0]))
		exit(EXIT_SUCCESS);
	else
		return (0);
	return (1);
}

int		parser(t_msh *data)
{
	char	**input;
	int		ret;

	ret = 0;
	if (!data->input[0] || is_assign(data))
		return (1);
	input = data->input;
	while (*input)
		exp_main(data, input++, 0);
	if (!**data->input)
		return (1);
	if ((ret = builtin_call(data)))
		return (ret);
	if (!ret && **data->input == '/')
		ret = exec_absolute_path(data);
	else if (!ret && !(ret = exec_path(data)))
		ret = exec_relative_path(data);
	if (!ret)
		ft_err(data->input[0], ": command not found");
	else if (ret == -1)
		ft_err(data->input[0], ": cannot execute the file");
	else if (ret == -2)
		ft_err(data->input[0], ": is a directory");
	return (ret);
}
