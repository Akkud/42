/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:46:26 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/16 15:15:44 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	a;
	size_t	b;
	size_t	destlen;
	size_t	srclen;

	a = 0;
	b = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen((char*)src);
	if (n)
	{
		while (dest[a])
			a++;
		while (src[b] && a < n - 1)
		{
			dest[a] = src[b];
			a++;
			b++;
		}
		dest[a] = '\0';
	}
	if (n >= destlen)
		return (destlen + srclen);
	return (srclen + n);
}
