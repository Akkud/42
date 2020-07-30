/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:24:38 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/06 19:29:46 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		ft_putchar(str[a]);
		a++;
	}
}

int		main(int ac, char **av)
{
	int a;

	a = 1;
	while (a < ac)
	{
		ft_putstr(av[a]);
		ft_putchar('\n');
		a++;
	}
	return (0);
}
