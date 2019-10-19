#include "../include/minishell.h"

int		main(int ac, char **av)
{
	char		buf[1024];
	char		*line;

	getcwd(buf, 1024);
	ft_printf("%s$> ", ft_strrchr(buf, '/') + 1);
	get_next_line(0, &line);
	
}
