/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:47:14 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/04 19:38:44 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int				main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		ret;
	int		ret2;
	char	*line;

	(void)ac;
	line = ft_strnew(99999);
	fd = open(av[1], O_RDONLY);
//	fd2 = open(av[2], O_RDONLY);
	ret = 1;
	ret2 = 1;
	while (ret > 0 && ret2 > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
//		ret2 = get_next_line(fd2, &line);
//		printf("%s\n", line);
	}
	return (0);
}
