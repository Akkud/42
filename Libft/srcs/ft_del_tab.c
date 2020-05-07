#include "libft.h"

void		ft_del_tab(void **tab)
{
	char	**target;
	int		i;

	i = 0;
	if (!tab || !*tab)
	{
		free(tab);
		return ;
	}
	target = (char **)tab;
	while (target[i])
		ft_strdel(&target[i++]);
	free(target);
}
