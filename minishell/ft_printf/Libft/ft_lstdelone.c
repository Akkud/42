/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:35:54 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:54:37 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst || !*alst)
		return ;
	del(((*alst)->content), (*alst)->content_size);
	ft_iferrfree((void**)alst, 0, 0, 0);
	*alst = NULL;
}
