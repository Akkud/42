/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toto.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:03:42 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/20 15:42:22 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void				*ft_strjoin(const char *s1, const char *s2)
{
	const size_t	len1 = strlen(s1);
	const size_t	len2 = strlen(s2);
	char			*ptr;
	char			*dst;

	ptr = malloc(len1 + len2 + 1);
	dst = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (dst);
}

void			*ft_getfile(const char *const file)
{
	const int	fd = open(file, O_RDONLY);
	char		*alloc;
	char		*tmp;
	char		buffer[42];
	ssize_t		readed;
	ssize_t		read_total;

	tmp = NULL;
	if (fd < 0)
		return (NULL);
	while ((readed = read(fd, buffer, 42)))
	{
		if (!tmp)
		{
			alloc = malloc((size_t)readed + 1);
			alloc[readed] = 0;
			memcpy(alloc, buffer, readed);
			tmp = alloc;
		}
		else
		{
			alloc = malloc((size_t)readed + 1);
			alloc[readed] = 0;
			memcpy(alloc, buffer, readed);
			alloc = ft_strjoin(tmp, alloc);
			tmp = alloc;
		}
	}
	close(fd);
	return (alloc);
}

#include <stdio.h>
int				main(int argc, char **argv)
{
	char		*ptr;

	if (*++argv)
	{
		ptr = ft_getfile(*argv);
		printf("%s:\n%s", *argv, ptr);
	}
	return (0);
}
