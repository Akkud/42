/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:25:42 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/07 18:42:19 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		ret;
	int		fd;

	(void)argc;
	ret = 1;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
