/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:53:20 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:53:21 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (i)
			ft_putchar(' ');
		ft_putstr(args[i]);
		i++;
	}
	ft_putchar('\n');
}
