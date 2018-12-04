/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:51:27 by guaubret          #+#    #+#             */
/*   Updated: 2018/12/04 17:12:33 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static t_file	*ft_get_file(t_file **f_list, const int fd)
{
	t_file	*file;

	file = *f_list;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	if (!(file = ft_memalloc(sizeof(t_file))))
		return (NULL);
	file->content = "\0";
	file->fd = fd;
	file->next = *f_list;
	*f_list = file;
	return (file);
}

static size_t	ft_strchrcpy(char **dst, char *src, char c)
{
	char *ptr;

	ptr = src;
	while (*src && *src != c)
		src++;
	*dst = ft_strnew(src - ptr + 1);
	*dst = ft_strncpy(*dst, ptr, (size_t)(src - ptr));
	return (src - ptr);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*f_list;
	char			buf[BUFF_SIZE + 1];
	ssize_t			ret;
	t_file			*file;
	size_t			i;

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || !(*line = ft_strnew(0)))
		return (-1);
	file = ft_get_file(&f_list, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(file->content = ft_strjoin(file->content, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	i = ft_strchrcpy(line, file->content, 10);
	if (ret < BUFF_SIZE && !ft_strlen(file->content))
		return (0);
	if (i < ft_strlen(file->content))
		file->content += (i + 1);
	else
		ft_strclr(file->content);
	return (1);
}

/*
**#include <stdio.h>
**
**int				main(int ac, char **av)
**{
**	int		fd;
**	int		ret;
**	char	*line;
**
**	(void)ac;
**	line = ft_strnew(99999);
**	fd = open(av[1], O_RDONLY);
**	ret = 1;
**	while (ret > 0)
**	{
**		ret = get_next_line(fd, &line);
**		printf("%s\n", line);
**	}
**	return (0);
**}
*/
