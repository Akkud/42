/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:38:45 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/16 17:47:10 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		reduce(char **tab, int x, int y)
{
	int i;

	i = 0;
	while (tab[i][x] && i <= y)
		if (tab[i++][x] != '.')
			return (0);
	i = 0;
	while (tab[y][i] && i <= x)
		if (tab[y][i++] != '.')
			return (0);
	i = 0;
	while (tab[i][x] && i <= y)
		tab[i++][x] = '\0';
	i = 0;
	while (tab[y][i] && i <= x)
		tab[y][i++] = '\0';
	return (1);
}
