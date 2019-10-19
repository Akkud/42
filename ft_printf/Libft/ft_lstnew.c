/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:27:44 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:55:09 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

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

/*
**int		main(int ac, char **av)
**{
**	(void)ac;
**	char	*content = av[1];
**	size_t	content_size = sizeof(content);
**	t_list	*res;
**
**	res = ft_lstnew(content, content_size);
**	printf("%s", res->content);
**	return (0);
**}
*/
