/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:43:44 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 16:51:44 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	*e;

	e = (unsigned char*)b;
	a = 0;
	while (a < len)
	{
		e[a] = (unsigned char)c;
		a++;
	}
	return (e);
}

/*
**int		main(int ac, char **av)
**{
**	char b[] = "Hello world!";
**	char b2[] = "Hello world!";
**
**	(void)ac;
**	if (ac == 3)
**	{
**		memset(b, atoi(av[1]), atoi(av[2]));
**		printf("Resultat 1 : %s\n", b);
**		ft_memset(b2, atoi(av[1]), atoi(av[2]));
**		printf("Resultat 2 : %s\n", b2);
**	}
**	else
**		printf("Pas le bon nombre d'arguments");
**	return (0);
**}
*/
