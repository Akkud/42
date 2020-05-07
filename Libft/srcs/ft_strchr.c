/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:02:16 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:14:11 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (str[a] == c)
			return ((char*)str + a);
		a++;
	}
	if (str[a] == c)
		return ((char*)str + a);
	return (0);
}
