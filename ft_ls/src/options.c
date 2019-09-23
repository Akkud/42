#include "ft_ls.h"

static int		is_option(char *str, t_lsdata *data)
{
	char	*err;

	if (str[0] != '-' || (str[0] == '-' && (str[1] == ' ' || !str[1])))
		return (0);
	if (str[0] == '-' && str[1] == '-' && (str[2] == ' ' || !str[2]))
		return (-2);
	if (!str[1])
		return (0);
	str++;
	while (*str)
	{
		if (!ft_strchr("lRart1C@", *str))
		{
			if (!(err = (char *)malloc(sizeof(char) * 2)))
				return (-1);
			err[0] = *str;
			err[1] = 0;
			if (!ft_error_handle(data, 2, err, 1))
				return (-1);
			free(err);
			return (-1);
		}
		str++;
	}
	return (1);
}

static void		store_option(char *str, t_lsdata *data)
{
	str++;
	while (*str)
	{
		data->display_f = (*str == 'l') ? 'l' : data->display_f;
		data->display_f = (*str == 'C') ? 'C' : data->display_f;
		data->display_f = (*str == '1') ? '1' : data->display_f;
		data->rr = (*str == 'R') ? 1 : data->rr;
		data->a = (*str == 'a') ? 1 : data->a;
		data->r = (*str == 'r') ? 1 : data->r;
		data->t = (*str == 't') ? 1 : data->t;
		data->at = (*str == '@') ? 1 : data->at;
		str++;
	}
}

char			*strip_name(char *av)
{
	int		i;

	i = ft_strlen(av);
	while (av[i] != '/' && i > 0)
		i--;
	if (av[i] == '/')
		i++;
	return (av + i);
}

int				get_options(char **av, int ac, t_lsdata **data)
{
	int		i;
	int		ret;

	if (!(*data = (t_lsdata *)malloc(sizeof(t_lsdata)))
	|| !((*data)->prog_name = ft_strdup(strip_name(av[0]))))
		return (-1);
	i = 0;
	ret = 1;
	(*data)->rr = 0;
	(*data)->a = 0;
	(*data)->r = 0;
	(*data)->t = 0;
	(*data)->at = 0;
	(*data)->display_f = '1';
	(*data)->errors = NULL;
	(*data)->pad = 0;
	while (++i < ac && (ret = is_option(av[i], *data)) > 0)
		store_option(av[i], *data);
	if (ret == -1)
		return (-1);
	if (ret == -2)
		i++;
	return (i);
}
