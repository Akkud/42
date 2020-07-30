/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:17:33 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:16:51 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;

	a = 0;
	if (!needle || !*needle)
		return ((char*)haystack);
	while (haystack[a])
	{
		b = 0;
		while (haystack[a] == needle[b] && haystack[a])
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
