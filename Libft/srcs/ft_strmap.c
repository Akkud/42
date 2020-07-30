/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:07:05 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:15:42 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		a;
	int		b;
	char	*str;

	if (!s)
		return (0);
	a = 0;
	b = ft_strlen((char*)s);
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
		return (0);
	str[b] = '\0';
	while (b)
	{
		str[a] = f(s[a]);
		a++;
		b--;
	}
	return (str);
}
