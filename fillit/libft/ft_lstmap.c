/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:02:49 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 16:49:54 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*alst;

	if (!(lst))
		return (0);
	alst = f(lst);
	if (!(alst = ft_lstnew(alst->content, alst->content_size)))
		return (0);
	res = alst;
	lst = lst->next;
	while (lst)
	{
		if (!ft_lstnewadd(&alst, f(lst)))
			return (0);
		lst = lst->next;
	}
	return (res);
}
