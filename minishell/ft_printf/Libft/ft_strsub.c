/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:08:17 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 19:00:04 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strncpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
