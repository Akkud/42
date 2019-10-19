/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sjoin1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:49:09 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:57:13 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_sjoin1(char **s1, char const *s2)
{
	char	*str;

	if (!s1 || !*s1 || !s2)
	{
		if (s1)
			ft_strdel(s1);
		return (0);
	}
	if (!(str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1)))
	{
		ft_strdel(s1);
		return (0);
	}
	ft_strcpy(str, *s1);
	ft_strcat(str, s2);
	ft_strdel(s1);
	return (str);
}
