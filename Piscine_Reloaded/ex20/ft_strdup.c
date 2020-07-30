/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:26:22 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/07 22:07:57 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		a;
	char	*str;

	a = 0;
	while (src[a])
		a++;
	if (!(str = (char*)malloc(sizeof(char) * (a + 1))))
		return (0);
	ft_strcpy(str, src);
	return (str);
}
