/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:32:54 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/14 18:36:58 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_lst;

	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp_lst = (*alst)->next;
		free(*alst);
		*alst = NULL;
		*alst = tmp_lst;
	}
}
