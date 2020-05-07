#include "minishell.h"

/*
**	MAN USED : https://www.unix.com/man-page/posix/1posix/cd/
*/

int			cd_setenv(t_env *env, char *name, char *value)
{
	while (env->name && ft_strcmp(env->name, name) && env->next)
		env = env->next;
	if (!env->name || (env->name && ft_strcmp(env->name, name) && !env->next))
		return (ft_setenv(env, name, value));
	free(env->value);
	if (!(env->value = ft_strdup(value)))
		return (0);
	return (1);
}

/*
**	Toujours passer un char** sans la string "cd" à la fonction cd.
*/

int			cd_oldpwd(t_msh *data)
{
	char		**str;
	char		*oldpwd;
	int			ret;

	oldpwd = ft_getenv(data->env, "OLDPWD");
	if (!oldpwd || !*oldpwd)
	{
		ft_printf("minishell: cd: OLDPWD not set\n");
		return (-1);
	}
	if (!(str = (char**)malloc(sizeof(char*) * 2)))
		return (0);
	str[0] = oldpwd;
	str[1] = NULL;
	ret = ft_cd(str, data);
	free(str);
	return (ret);
}

int			ft_cd(char **str, t_msh *data)
{
	char	opt;
	char	*opr;
	char	*curpath;
	int		i;

	i = 0;
	if (!(opt = cd_getopt(str, &i)))
		return (-1);
	opr = str[i];
	if (!opr)
		return (cd_home(data));
	else if (!ft_strcmp(opr, "-"))
		return (cd_oldpwd(data));
	if (!(curpath = cd_setcurpath(data, opr)))
		return (0);
	if (opt == 'L')
		return (cd_logically(data, curpath, opr));
	return (cd_change_directory(data, curpath, opr, NULL));
}
