/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:45:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:16:05 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t a;

	a = 0;
	if (!dest || !src)
		return (0);
	while (src[a] && a < len)
	{
		dest[a] = src[a];
		a++;
	}
	while (a < len)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}
