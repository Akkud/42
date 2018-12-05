/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:02:45 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/19 19:42:14 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1)))
		return (0);
	ft_strcpy(str, (char*)s1);
	ft_strcat(str, s2);
	return (str);
}
