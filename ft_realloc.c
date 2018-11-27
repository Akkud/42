/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:24:00 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/20 19:37:40 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_realloc(void *ptr, size_t size)
{
	void	*res;

	if (size)
		if (!(res = (void*)malloc(size)))
			return (0);
	if (ptr)
	{
		if (size)
			ft_memcpy(res, ptr, size);
		free(ptr);
	}
	return (res);
}
