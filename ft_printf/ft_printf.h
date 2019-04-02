#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_printf
{
	void	*arg;
	char	flag[6];
	char	*fw;
	char	*pr;
	int		lmod;
}				t_printf;






