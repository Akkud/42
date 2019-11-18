#include "../include/minishell.h"

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

t_env	*ft_setenvlist(char **env, char *name, char *value)
{
	int		i;
	t_env	*ret;
	t_env	*new;

	i = 0;
	if (!(ret = malloc(sizeof(t_env))))
		return (0);
	ret->name = NULL;
	ret->value = NULL;
	ret->next = NULL;
	if (!*env)
		return (ret);
	ret->name = ft_strcut(env[i], "=", 1);
	ret->value = ft_strcut(env[i], "=", 2);
	ret->next = NULL;
	i++;
	while (env[i])
	{
		if (!(ft_envaddnext(ret, ft_strcut(env[i], "=", 1),
			ft_strcut(env[i], "=", 2))))
			return (0);
		i++;
	}
	return (ret);
}

int		ft_envaddnext(t_env *env, char *name, char *value)
{
	while (env->next)
		env = env->next;
	if (env->name && env->value)
	{
		if (!(env->next = (t_env*)malloc(sizeof(t_env))))
			return (0);
		env = env->next;
	}
	if (!(env->name = ft_strdup(name)))
	{
		free(env);
		return (0);
	}
	if (!(env->value = ft_strdup(value)))
	{
		free(env->name);
		free(env);
		return (0);
	}
	env->next = NULL;
	return (1);
}
