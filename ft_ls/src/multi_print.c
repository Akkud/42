#include "ft_ls.h"

int				ft_get_largest_str(char **tab, int size, int col_n, int col)
{
	int	i;
	int	max;
	int	res;
	int	lines;

	lines = size / col_n;
	if (size % col_n > 0)
		lines++;
	max = (col == col_n - 1) ? size : (lines * (col + 1));
	i = lines * col;
	res = 0;
	if (i >= max)
		return (0);
	while (i < max)
	{
		if ((int)ft_strlen(tab[i]) > res)
			res = ft_strlen(tab[i]);
		i++;
	}
	if (col == col_n - 1)
		return (res);
	return (res + 2);
}

static int		ft_check_col(char **tab, int size, int col_n, int win_w)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < col_n)
		res += ft_get_largest_str(tab, size, col_n, i++);
	if (res > win_w)
		return (0);
	return (1);
}

static int		get_max_col(char **tab, int tab_size, int win_w)
{
	int	res;
	int	lines;
	int	col_n;

	lines = 1;
	col_n = tab_size;
	res = 0;
	while (col_n > 0 && !(res = ft_check_col(tab, tab_size, col_n, win_w)))
	{
		lines++;
		col_n = tab_size / lines;
		if (tab_size % lines > 0)
			col_n++;
	}
	if (col_n <= 0)
		return (0);
	return (col_n);
}

static void		ft_print_multi_col(char **tab, int size, int cols, int *col_l)
{
	int	i;
	int	j;
	int	k;
	int	lines;

	i = -1;
	lines = size / cols;
	if (size % cols > 0)
		lines++;
	while (++i < lines)
	{
		j = -1;
		while (++j < cols - 1)
			if (i + j * lines < size - 1)
			{
				ft_printf("%s", tab[i + j * lines]);
				k = 0;
				while (k < (int)(col_l[j] - ft_strlen(tab[i + j * lines]))
				&& k++ < col_l[j])
					ft_printf("%c", ' ');
			}
		if (i + j * lines < size)
			ft_printf("%s", tab[i + j * lines]);
		ft_printf("\n");
	}
}

int				ft_multi_display(t_lsfile *file, int win_w)
{
	int			i;
	int			col;
	int			*col_l;
	char		**tab;
	t_lsfile	*tmp;

	i = 0;
	tmp = file;
	while (!tmp++->end)
		i++;
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (0);
	i = 0;
	tmp = file;
	while (!tmp->end)
		tab[i++] = ft_strdup(tmp++->name);
	tab[i] = NULL;
	col = get_max_col(tab, i, win_w);
	if (!(col_l = (int *)malloc(sizeof(int) * col)))
		return (0);
	get_col_lengths(tab, i, col, col_l);
	ft_print_multi_col(tab, i, col, col_l);
	free(col_l);
	ft_clean_str_tab(tab);
	return (1);
}
