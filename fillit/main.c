/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:55:47 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/16 17:47:05 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int error)
{
	if (error == 1)
		write(1, "error\n", 6);
	if (error == 2)
		write(1, "usage: ./fillit target_file\n", 28);
	return (0);
}

int		main(int ac, char **av)
{
	char	**tab;
	
	if (ac != 2)
		return (ft_error(2));
	if (!(read_main(av[1], &tab)))
		return (ft_error(1));
	if (!(checki_breeki(tab)))
		return (ft_error(1));
	ft_print_words_tables(tab);
	return (0);
}
