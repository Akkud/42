/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:06:27 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/15 16:40:41 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n_lst;
	t_list	*h_lst;
	t_list	*ret;

	if (!lst || !(h_lst = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	h_lst = f(lst);
	ret = h_lst;
	if (!ret)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if (!(n_lst = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		n_lst = f(lst);
		h_lst->next = n_lst;
		h_lst = h_lst->next;
		lst = lst->next;
	}
	return (ret);
}
