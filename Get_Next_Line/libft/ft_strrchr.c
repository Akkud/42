/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:08:05 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 16:57:30 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	while (a > -1)
	{
		if (str[a] == c)
			return ((char*)str + a);
		a--;
	}
	return (0);
}
