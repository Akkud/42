#include "libft.h"

void		ft_lstfree(t_list **lst)
{
	t_list	*tmp;

	while (tmp = *lst)
	{
		*lst = (*lst)->next;
		ft_memdel(&tmp->data);
		ft_memdel(&tmp);
	}
}
