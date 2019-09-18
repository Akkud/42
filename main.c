#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

int main(int ac, char **av)
{
	int i;
	i = 0;
	t_stock_str *tab2;
	tab2 = ft_strs_to_tab(ac, av);
	ft_show_tab(tab2);
}
