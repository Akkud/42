/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:20:14 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:55:48 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*src2;
	size_t	a;

	str = (char*)dst;
	src2 = (char*)src;
	a = 0;
	while (a < n)
	{
		str[a] = src2[a];
		a++;
	}
	return (str);
}
