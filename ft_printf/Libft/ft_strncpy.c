/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:45:20 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:59:19 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t a;

	a = 0;
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
