#include "ft_ls.h"

void		ft_single_print(t_lsfile *file)
{
	while (!file->end)
	{
		ft_printf("%s\n", file->name);
		file++;
	}
}
