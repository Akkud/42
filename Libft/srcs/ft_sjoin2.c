/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sjoin2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:49:26 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:13:55 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sjoin2(char const *s1, char **s2)
{
	char	*str;

	if (!s1 || !s2 || !*s2)
	{
		if (s2)
			ft_strdel(s2);
		return (0);
	}
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(*s2) + 1)))
	{
		ft_strdel(s2);
		return (0);
	}
	ft_strcpy(str, s1);
	ft_strcat(str, *s2);
	ft_strdel(s2);
	return (str);
}
