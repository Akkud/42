/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:05:50 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/19 18:47:10 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	a = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (a < n - 1 && str1[a] == str2[a])
		a++;
	return (str1[a] - str2[a]);
}
