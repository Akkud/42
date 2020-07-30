/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:27:44 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/07 18:07:39 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list*)malloc(sizeof(*res))))
		return (0);
	if (!content || !content_size)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if (!(res->content = ft_memalloc(content_size)))
			return (0);
		ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
