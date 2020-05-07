#include "minishell.h"

void	ft_echo(char **args)
{
	int		i;;

	i = 0;
	while (args[i])
	{
		if (i)
			ft_putchar(' ');
		ft_putstr(args[i]);
		i++;
	}
	ft_putchar('\n');
}
