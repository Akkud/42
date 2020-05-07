#include "libft.h"


int		count_words(char *str, char *set)
{
	int words;

	words = 0;
	while (*str)
	{
		if (!ft_strchr(set, *str))
		{
			words++;
			while (*str && !ft_strchr(set, *str))
				str++;
		}
		while (*str && ft_strchr(set, *str))
			str++;
	}
	return (words);
}

int		word_len(char *str, char *set)
{
	int		ret;

	ret = 0;
	while (!ft_strchr(set, *str))
	{
		ret++;
		str++;
	}
	return (ret);
}

char	**ft_split(char *str, char *set)
{
	char	**ret;
	int		words;
	int		wlen;
	int		i;

	words = count_words(str, set);
	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * (words + 1))))
		return (0);
	ret[words] = NULL;
	while (*str)
	{
		if (!ft_strchr(set, *str))
		{
			wlen = word_len(str, set);
			if (!(ret[i] = ft_strndup(str, wlen)))
			{
				ft_del_tab((void**)ret);
				return (0);
			}
			str += wlen;
			i++;
		}
		while (*str && ft_strchr(set, *str))
			str++;
	}
	return (ret);
}
