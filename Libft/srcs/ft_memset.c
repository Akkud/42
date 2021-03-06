/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:43:44 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:12:19 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	*e;

	e = (unsigned char*)b;
	a = 0;
	while (a < len)
	{
		e[a] = (unsigned char)c;
		a++;
	}
	return (e);
}
