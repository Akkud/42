#include "minishell.h"

char	*ft_getenv(t_env *env, char *name)
{
	char		*res;

	res = NULL;
	while (env && !res)
	{
		if (env->name && !ft_strcmp(name, env->name))
		{
			res = env->value;
			if (!res || !*res)
				return (NULL);
		}
		env = env->next;
	}
	return (res);
}

t_env	*ft_setenvlist(char **env)
{
	t_env	*ret;
	char	*name;
	char	*value;

	if (!(ret = (t_env *)ft_memalloc(sizeof(t_env))))
		ft_ex("minishell: cannot allocate memory");
	if (!*env)
		return (ret);
	if (!(ret->name = ft_strcut(*env, "=", 1))
	|| !(ret->value = ft_strdup(ft_strchr(*env, '=') + 1)))
		ft_ex("minishell: cannot allocate memory");
	ret->next = NULL;
	env++;
	while (*env)
	{
		if (!(name = ft_strcut(*env, "=", 1))
		|| !(value = ft_strdup(ft_strchr(*env, '=') + 1)))
			ft_ex("minishell: cannot allocate memory");
		ft_setenv(ret, name, value);
		free(name);
		free(value);
		env++;
	}
	return (ret);
}

int		ft_setenv(t_env *env, char *name, char *value)
{
	if (!ft_isname(name))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": not a valid name", 2);
		return (0);
	}
	while (env->next)
		env = env->next;
	if (env->name)
	{
		if (!(env->next = (t_env*)ft_memalloc(sizeof(t_env))))
			ft_ex("minishell: cannot allocate memory");
		env = env->next;
	}
	if (!(env->name = ft_strdup(name)))
		ft_ex("minishell: cannot allocate memory");
	if (!(env->value = ft_strdup(value)))
		ft_ex("minishell: cannot allocate memory");
	env->next = NULL;
	return (1);
}

int		ft_unsetenv(t_msh *data, char *name)
{
	t_env	*env;
	t_env	*prev;

	env = data->env;
	prev = NULL;
	while (env)
	{
		if (!ft_strcmp(name, env->name))
		{
			if (!prev)
				data->env = env->next;
			else
				prev->next = env->next;
			free(env->name);
			free(env->value);
			free(env);
			return (1);
		}
		prev = env;
		env = env->next;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": environment variable not found", 2);
	return (0);
}

void		ft_env(t_msh *data)
{
	t_env		*env;

	env = data->env;
	while (env)
	{
		ft_printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
}
