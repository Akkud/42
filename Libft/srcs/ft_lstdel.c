/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:17:03 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:10:52 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *l;

	l = *alst;
	while (*alst)
	{
		del(((*alst)->content), (*alst)->content_size);
		free(*alst);
		*alst = (*alst)->next;
	}
	l = NULL;
	(void)l;
}
