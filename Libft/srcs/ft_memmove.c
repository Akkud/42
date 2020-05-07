/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:23:52 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/07 18:07:27 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	size_t				a;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	if (src1 < dst1)
	{
		a = len;
		while (a-- > 0)
			dst1[a] = src1[a];
	}
	else
	{
		a = 0;
		while (a < len)
		{
			dst1[a] = src1[a];
			a++;
		}
	}
	return (dst1);
}
