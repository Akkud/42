/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:55:53 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:58:01 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		print_prompt(t_msh *data)
{
	int		i;
	int		slash;
	char	*home;
	int		homelen;

	i = -1;
	slash = 0;
	while (data->cwd[++i])
		if (data->cwd[i] == '/' && (i == 0 || data->cwd[i - 1] != '\\'))
			slash++;
	if ((home = ft_getenv(data->env, "HOME")))
	{
		homelen = ft_strlen(home);
		if (!ft_strncmp(home, data->cwd, homelen)
		&& (data->cwd[homelen] == '/' || !data->cwd[homelen]))
		{
			ft_printf("~%s » ", data->cwd + homelen);
			return (1);
		}
	}
	if (slash < 7)
		ft_printf("%s » ", data->cwd);
	else
		ft_printf("%s » ", ft_strrchr(data->cwd, '/') + 1);
	return (1);
}

void	ft_prompt(t_msh *data)
{
	char		*line;

	if (!(data->cwd = getcwd(NULL, 0)))
		ft_ex(NULL, "cannot allocate memory\n");
	ft_putstr("\e[36m");
	print_prompt(data);
	ft_putstr("\e[39;49m");
	get_next_line(0, &line);
	if (!(data->input = ft_split(line, " \t")))
	{
		ft_printf("oh no split !\n");
		ft_ex(NULL, "cannot allocate memory\n");
	}
	free(line);
}

int		main(int ac, char **av, char **envp)
{
	t_msh		data;

	(void)ac;
	(void)av;
	if (!(data.env = ft_setenvlist(envp)))
		ft_ex(NULL, "cannot allocate memory\n");
	while (1)
	{
		ft_prompt(&data);
		parser(&data);
		free_memory(&data);
	}
	return (0);
}
