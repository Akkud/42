/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:03:22 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:57:49 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				a;
	unsigned char	*ss1;
	unsigned char	*ss2;

	a = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (ss1[a] && ss2[a] && ss1[a] == ss2[a])
		a++;
	return (ss1[a] - ss2[a]);
}
