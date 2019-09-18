#include "ft_stock_str.h"
#include "stdlib.h"

int ft_strlen(char *str);
char *ft_strcpy(char *dest, char *src);

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	t_stock_str *tab;

	i = 0;
	if(!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	while (ac > i)
	{
	tab[i].size = ft_strlen(av[i]);
	tab[i].str = av[i];
	if(!(tab[i].copy = malloc(sizeof(char) * (tab[i].size + 1))))
		return (0);
	ft_strcpy(tab[i].copy, av[i]);
	i++;
	}
	tab[i].str = 0;
	return (tab);
}
