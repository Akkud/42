/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:29:54 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/20 16:23:35 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_len(char const *s, char c)
{
	int a;

	a = 0;
	while (s[a] != c && s[a])
		a++;
	return (a);
}

static int		count_words(char const *s, char c)
{
	int a;
	int cw;

	a = 0;
	cw = 0;
	while (s[a])
	{
		if (s[a] != c)
		{
			cw++;
			while (s[a] && s[a] != c)
				a++;
		}
		while (s[a] == c)
			a++;
	}
	return (cw);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s)
		return (0);
	if (!(tab = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (0);
	while (s[a])
	{
		if (s[a] != c)
		{
			if (!(tab[b++] = ft_strsub(s, a, word_len(s + a, c))))
				return (0);
			while (s[a] && s[a] != c)
				a++;
		}
		while (s[a] == c && s[a])
			a++;
	}
	tab[b] = 0;
	return (tab);
}
