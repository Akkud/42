/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:05:18 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/23 01:50:17 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;

	if (!src || !dst)
		return (0);
	d = dst;
	s = src;
	n = size;
	if (n)
		while (--n && (*d++ = *s++))
			;
	if (!n)
	{
		if (size)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
