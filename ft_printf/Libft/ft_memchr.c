/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 22:06:26 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:55:37 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*str;
	unsigned char	b;

	a = 0;
	str = (unsigned char*)s;
	b = (unsigned char)c;
	while (a < n)
		if (str[a++] == b)
			return (str + --a);
	return (0);
}
