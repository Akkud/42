/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:33:45 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/19 18:56:19 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_print_words_tables(char **tab)
{
	int		a;
	int		c;

	a = 0;
	c = 0;
	while (tab[a])
	{
		while (tab[a][c])
		{
			ft_putchar(tab[a][c]);
			c++;
		}
		c = 0;
		ft_putchar('\n');
		a++;
	}
}
