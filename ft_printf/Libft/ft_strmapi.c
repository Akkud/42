/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:24:16 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:59:01 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[a] = f(a, s[a]);
		a++;
		b--;
	}
	return (str);
}
