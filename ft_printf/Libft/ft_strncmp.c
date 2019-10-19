/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:05:32 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:59:12 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			a;
	unsigned char	*ss1;
	unsigned char	*ss2;

	a = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	if (len == 0)
		return (0);
	while (ss1[a] && ss2[a] && ss1[a] == ss2[a] && a < len - 1)
		a++;
	return (ss1[a] - ss2[a]);
}
