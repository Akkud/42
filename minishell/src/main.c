/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:17:22 by pacharbo          #+#    #+#             */
/*   Updated: 2019/11/15 20:59:41 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		print_prompt(t_msh data)
{
	int	i;
	int	slash;
	char	*home;
	size_t	homelen;

	i = -1;
	slash = 0;
	while (data.cwd[++i])
		if (data.cwd[i] == '/' && (i == 0 || data.cwd[i - 1] != '\\'))
			slash++;
	if ((home = ft_getenv(data.env, "HOME")))
	{
		homelen = ft_strlen(home);
		if (!ft_strncmp(home, data.cwd, homelen)
		&& (data.cwd[homelen] == '/' || !data.cwd[homelen]))
		{
			ft_printf("~%s » ", data.cwd + homelen);
			return (1);
		}
	}
	if (slash == 1)
		ft_printf("%s » ", data.cwd);
	else
		ft_printf("%s » ", ft_strrchr(data.cwd, '/') + 1);
	return (1);
}

int		main(int ac, char **av, char **envp)
{
	char		*line;
	char		*tmp;
	t_msh		data;
//		display env
	t_env	*env;
//
	if (!(data.env = ft_setenvlist(envp, NULL, NULL)))
	{
			printf("oh no setenvlist !\n");
			return (0);
	}

//	printf("PATH=[%s]\n", ft_getenv("PATH"));
	while (1)
	{
//	===============Affichage PROMPT================
		if (!(data.cwd = getcwd(NULL, 0)))
		{
			printf("oh no getcwd !\n");
			return (0);
		}
		print_prompt(data);
//	===============================================
		get_next_line(0, &line);

/*		Tests strcut
**
**		tmp = ft_strcut(line, " ", 1);
**		ft_printf("premier argument : [%s]\n", tmp);
**		free(tmp);
**		tmp = ft_strcut(line, " ", 2);
**		ft_printf("second argument : [%s]\n", tmp);
*/
		if (!(data.input = ft_strsplit(line, ' ')))
		{
			printf("oh no split !\n");
			return (0);
		}
		int 	ret;
		if (data.input[0] && !ft_strcmp("cd", data.input[0]))
		{
				ret = ft_cd(data.input + 1, &data);
				if (ret < 1)
					printf("cd a retourné %d !\n", ret);
		}
		else if (data.input[0] && !ft_strcmp("pwd", data.input[0]))
			ft_printf("%s\n", data.cwd);
		else if (data.input[0] && !ft_strcmp("sortir", data.input[0]))
			return (0);
		else if (data.input[0] && !ft_strcmp("env", data.input[0]))
//		============== Display env list ===============
		{
			env = data.env;
			while (env)
			{
				printf("%s=%s\n", env->name, env->value);
				env = env->next;
			}
		}
//		===============================================
	}
	return (0);
}
