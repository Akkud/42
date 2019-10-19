/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:07:45 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:55:15 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int		ft_lstnewadd(t_list **alst, t_list *new)
{
	t_list	*res;

	if (!(res = (t_list*)malloc(sizeof(*res))))
		return (0);
	if (!new->content)
	{
		res->content = NULL;
		res->content_size = new->content_size;
	}
	else
	{
		if (!(res->content = ft_memalloc(new->content_size)))
			return (0);
		ft_memcpy(res->content, new->content, new->content_size);
		res->content_size = new->content_size;
	}
	(*alst)->next = res;
	res->next = NULL;
	*alst = (*alst)->next;
	return (1);
}
