#include "../include/minishell.h"

/*
**	MAN USED : https://www.unix.com/man-page/posix/1posix/cd/
**
**
**
**	Steps 1 & 2
*/

int		cd_home(t_msh *data)
{
	char	**str;
	char	*home;
	int		ret;

	home = ft_getenv(data->env, "HOME");
	if (!home || !*home)
	{
		ft_printf("minishell: cd: HOME not set\n");
		return (-1);
	}
	if (!(str = (char**)malloc(sizeof(char*) * 2)))
		return (0);
	str[0] = home;
	str[1] = NULL;
	ret = ft_cd(str, data);
	free(str);
	return (ret);
}

/*
**	Steps 3 to 6
*/

char	*cd_setcurpath(t_msh *data, char *opr)
{
	char	*ret;
	char	**cdpath;

	if (*opr != '/' && (ft_strncmp(opr, "./", 2) || ft_strcmp(opr, "."))
			&& ((ft_strncmp(opr, "../", 3)) || ft_strcmp(opr, "..")))
		return (ft_strdup(opr));
	ret = ft_getenv(data->env, "CDPATH");
	cdpath = ft_strsplit(ret, ':');
	while (cdpath && *cdpath)
	{
		ret = ft_pathjoin(*cdpath, opr);
		if (ft_isdir(ret))
			break ;
		free(ret);
		cdpath++;
	}
	ft_clean_str_tab(cdpath);
	if (!ret && (ft_isdir(opr)))
		return (ft_strdup(opr));
	return (ret);
}

/*
**	Steps 7 & 8
*/

int		cd_logically(t_msh *data, char *curpath, char *opr)
{
	char	*tmp;
	char	*pwd;

	if (!(pwd = ft_strdup(ft_getenv(data->env, "PWD"))))
		if (!(pwd = getcwd(NULL, 0)))
			return (0);
	if (*curpath != '/')
	{
		tmp = curpath;
		curpath = ft_pathjoin(pwd, curpath);
		free(tmp);
	}
	if (!(curpath = cd_del_dotcomponents(curpath, opr)))
		return (0);
	return (cd_set_relativepath(data, curpath, opr, pwd));
}

/*
**	Step 9
*/

int		cd_set_relativepath(t_msh *data, char *curpath, char *opr, char *pwd)
{
	char	*tmp;
	char	*oldpath;
	int		ret;

	oldpath = ft_strdup(curpath);
	if (ft_strlen(curpath) >= PATH_MAX && ft_strlen(opr) < PATH_MAX
	&& !ft_strncmp(curpath, pwd, ft_strlen(pwd)))
	{
		tmp = curpath[ft_strlen(pwd)] == '/' ?
		ft_strdup(curpath + ft_strlen(pwd) + 1) :
		ft_strdup(curpath + ft_strlen(pwd));
		curpath = tmp;
	}
	free(pwd);
	ret = cd_change_directory(data, curpath, opr, oldpath);
	free(oldpath);
	return (ret);
}

/*
**	Step 10
*/

int		cd_change_directory(t_msh *data, char *curpath, char *opr, char *pwd)
{
	char	*oldpwd;
	char	*error;

	if (!(oldpwd = ft_strdup(ft_getenv(data->env, "PWD"))))
		if (!(oldpwd = getcwd(NULL, 0)))
			return (0);
	if (chdir(curpath) == -1)
	{
		check_chdir_errors(&error, curpath, opr);
		return (display_cd_errors(error));
	}
	free(curpath);
	if (!pwd && !(pwd = getcwd(NULL, 0)))
		return (0);
	if (!cd_setenv(data->env, "PWD", pwd)
	|| !cd_setenv(data->env, "OLDPWD", oldpwd))
		return (0);
	free(oldpwd);
	return (1);
}
