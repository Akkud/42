/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:00:15 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/07 15:18:54 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		a;
	int		*tab;

	a = 0;
	if (min >= max)
		tab = NULL;
	else
	{
		if (!(tab = (int*)malloc(sizeof(int) * (max - min))))
			return (0);
		while (min < max)
		{
			tab[a++] = min;
			min++;
		}
	}
	return (tab);
}
