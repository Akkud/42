/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:54:20 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/16 15:37:24 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(char *av, char ***tab)
{
	int		i;
	int		fd;
	int		ret;

	i = 0;
	fd = open(av, O_RDONLY);
	if (!(*tab = (char**)malloc(sizeof(char*) * 130)))
		return (0);
	while ((ret = get_next_line(fd, &(tab[0][i]))) > 0)
	{
		if (i == 129)
			return (0);
		i++;
	}
	if (ret < 0 || (i + 1) % 5)
		return (0);
	tab[0][i] = NULL;
	close(fd);
	return (1);
}

int		read_main(char *av, char ***tab)
{
	if (!(ft_read(av, tab)))
		return (0);
	return (1);
}
