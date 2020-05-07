#include "minishell.h"
#include "libft.h"

char	*resolve_parameter(t_msh *data, char *str)
{
	int		i;
	char	*res;

	i = -1;
	if (!(ft_strlen(str) == 1 && (*str == '@' || *str == '*'
	|| *str == '#' || *str == '?' || *str == '-' || *str == '$'
	|| *str == '!' || ft_isdigit(*str)))
	&& !ft_isname(str))
		return (NULL);
	if ((res = ft_getenv(data->env, str))
	&& !(res = ft_strdup(res)))
		ft_ex("Cannot allocate memory\n");
	if (!res && !(res = ft_strnew(0)))
		ft_ex("Cannot allocate memory\n");
	return (res);
}
