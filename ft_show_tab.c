#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void ft_show_tab(struct s_stock_str *par)
{
	int i;
	i = 0;
	while (par[i].str)
	{
	ft_putstr(par[i].str);
	write(1, "\n",1);
	ft_putnbr(par[i].size);
	write(1, "\n",1);
	ft_putstr(par[i].copy);
	write(1, "\n",1);
	i++;
	}
}


