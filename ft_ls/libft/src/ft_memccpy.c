/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:00:04 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/15 20:01:57 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!n)
		return (NULL);
	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	while (n--)
		if ((*str2++ = *str1++) == (unsigned char)c)
			return (str2);
	return (NULL);
}
