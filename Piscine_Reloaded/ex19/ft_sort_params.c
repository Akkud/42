/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:30:16 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/07 15:35:36 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while (s1[a] && s2[a] && s1[a] == s2[a])
		a++;
	return (s1[a] - s2[a]);
}

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
	int		a;
	char	*str;

	a = 1;
	while (a < ac - 1)
	{
		if (ft_strcmp(av[a], av[a + 1]) > 0)
		{
			str = av[a];
			av[a] = av[a + 1];
			av[a + 1] = str;
			a = 0;
		}
		a++;
	}
	a = 1;
	while (a < ac)
	{
		ft_putstr(av[a]);
		ft_putchar('\n');
		a++;
	}
	return (0);
}
