/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:43:39 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:11:41 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			a;
	unsigned char	*src2;
	unsigned char	*str;
	unsigned char	b;

	a = 0;
	src2 = (unsigned char*)src;
	str = (unsigned char*)dst;
	b = (unsigned char)c;
	while (a < n)
	{
		str[a] = src2[a];
		if (src2[a] == b)
			return ((void*)str + a + 1);
		a++;
	}
	return (NULL);
}
