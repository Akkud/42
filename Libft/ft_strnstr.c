/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:00:40 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/14 16:31:52 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	int		b;

	a = 0;
	b = 0;
	if (!(needle[0]))
		return ((char*)haystack);
	while (haystack[a] && a < len)
	{
		b = 0;
		while (haystack[a] == needle[b] && haystack[a] && a < len)
		{
			a++;
			b++;
		}
		if (!needle[b])
			return ((char*)haystack + a - b);
		else if (!(haystack[a]))
			break ;
		else
			a = a - b;
		a++;
	}
	return (0);
}
