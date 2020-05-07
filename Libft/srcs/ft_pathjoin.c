/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:16:11 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:12:29 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_pathjoin(char *str1, char *str2)
{
	char	*ret;
	char	*tmp;
	size_t	s1len;

	if (!str1 || !str2)
		return (0);
	s1len = ft_strlen(str1);
	if (!s1len || (str1[s1len - 1] == '/'))
		return (ft_strjoin(str1, str2));
	if (!(tmp = ft_strjoin(str1, "/")))
		return (0);
	ret = ft_strjoin(tmp, str2);
	free(tmp);
	return (ret);
}
