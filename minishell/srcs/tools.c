#include "minishell.h"

void	ft_ex(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	free_memory(t_msh *data)
{
	ft_strdel(&data->cwd);
	ft_del_tab((void**)data->input);
}
