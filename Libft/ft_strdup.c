/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:26:22 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/24 17:58:45 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strdup(const char *src)
{
	int		a;
	char	*str;

	a = 0;
	if (!src)
		return (0);
	while (src[a])
		a++;
	if (!(str = (char*)malloc(sizeof(char) * (a + 1))))
		return (0);
	ft_strcpy(str, src);
	return (str);
}
