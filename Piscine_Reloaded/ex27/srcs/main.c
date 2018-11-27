/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:35:53 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/07 21:47:43 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		a;
	char	str[1];

	if (ac < 2)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		if ((a = open(av[1], O_RDONLY)) < 0)
			return (0);
		while (read(a, str, 1) > 0)
			write(1, str, 1);
	}
	return (0);
}
