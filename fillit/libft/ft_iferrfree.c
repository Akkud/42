/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iferrfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:23:54 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 16:46:54 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long	ft_iferrfree(void **pt1, void **pt2, void **pt3, void **pt4)
{
	if (pt1)
		if (*pt1)
			ft_memdel(pt1);
	if (pt2)
		if (*pt2)
			ft_memdel(pt2);
	if (pt3)
		if (*pt3)
			ft_memdel(pt3);
	if (pt4)
		if (*pt4)
			ft_memdel(pt4);
	return (0);
}
/*
**#include <unistd.h>
**
**int		main(void)
**{
**	char	*str;
**	int		*cc;
**
**	str = (char*)malloc(65);
**	cc = (int*)(malloc(sizeof(int) * 15));
**	if (ft_iferrfree(str, cc, 0, 0))
**		write(1, "OK", 2);
**	return (0);
**}
*/
