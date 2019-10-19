/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:41:28 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:58:43 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t		ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = ft_strlen(src);
	if (size)
	{
		while (src[a] && a < size - 1)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (b);
}
