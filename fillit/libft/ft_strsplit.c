/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:46:18 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/16 19:35:45 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_wordcount(char const *s, char c)
{
	int		ctr;

	ctr = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			ctr++;
		}
		else
			while (*s == c)
				s++;
	}
	return (ctr);
}

static int			*ft_wordlength(char const *s, char c, int word_c)
{
	int		*tab;
	int		*ret;

	if (!(tab = (int*)malloc(sizeof(int) * (word_c + 1))))
		return (NULL);
	ret = tab;
	while (*s)
	{
		*tab = 0;
		if (*s != c)
		{
			while (*s != c && *s)
			{
				(*tab)++;
				s++;
			}
			tab++;
		}
		else
			while (*s == c)
				s++;
	}
	*tab = 0;
	return (ret);
}

static char const	*ft_get_next_word(char const *s, char c)
{
	char	*str;

	str = (char *)s;
	if (*str != c && *str)
		while (*str != c && *str)
			str++;
	if (*str == c && *str)
		while (*str == c && *str)
			str++;
	return ((char const *)str);
}

char				**ft_strsplit(char const *s, char c)
{
	int			word_c;
	int			*word_l;
	char		**tab;
	char const	*tmp_s;
	char		**ret;

	if (s == NULL)
		return (NULL);
	word_c = ft_wordcount(s, c);
	if (!(word_l = ft_wordlength(s, c, word_c)))
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char*) * (word_c + 1))))
		return (NULL);
	ret = tab;
	tmp_s = s;
	if (s[0] == c)
		tmp_s = ft_get_next_word(s, c);
	while (word_c--)
	{
		if (!(*tab++ = ft_strsub(tmp_s, 0, (*word_l++))))
			return (NULL);
		tmp_s = ft_get_next_word(tmp_s, c);
	}
	*tab = NULL;
	return (ret);
}
