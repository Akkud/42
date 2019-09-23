/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:09:02 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/11 22:25:05 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (const unsigned char *)src;
	if (str1 < str2)
		while (len--)
			*str1++ = *str2++;
	else
	{
		str1 += len;
		str2 += len;
		while (len--)
			*--str1 = *--str2;
	}
	return (dst);
}
