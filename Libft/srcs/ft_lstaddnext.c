/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:53:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:10:43 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddnext(t_list **alst, t_list *new)
{
	(*alst)->next = new;
	new->next = NULL;
	*alst = (*alst)->next;
}