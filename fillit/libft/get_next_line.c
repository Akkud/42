/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:51:27 by guaubret          #+#    #+#             */
/*   Updated: 2018/12/08 19:52:36 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_cut_str(char *str, size_t i)
{
	char *ret;

	if (!(ret = ft_strnew(ft_strlen(str) - i)) || !str)
		return (NULL);
	if (i < ft_strlen(str))
		ret = ft_strcpy(ret, str + i + 1);
	free(str);
	return (ret);
}

static char		*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2 || !(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (!(new = ft_strcat(new, s1))
	|| !(new = ft_strcat(new, s2)))
		return (NULL);
	free(s1);
	return (new);
}

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
	if (!(file = ft_memalloc(sizeof(t_file)))
	|| !(file->content = (char*)malloc(BUFF_SIZE + 1)))
		return (NULL);
	file->fd = fd;
	file->next = *f_list;
	*f_list = file;
	return (file);
}

static size_t	ft_strchrcpy(char **dst, char *src, char c)
{
	char *ptr;

	if (!dst || !src)
		return (0);
	ptr = src;
	while (*src && *src != c)
		src++;
	free(*dst);
	if (!(*dst = ft_strnew(src - ptr + 1)))
		return (0);
	*dst = ft_strncpy(*dst, ptr, (size_t)(src - ptr));
	return (src - ptr);
}

void			ft_fddel(t_file **f_list, int fd)
{
	t_file	*tmp;
	t_file	*curr;

	curr = *f_list;
	if ((*f_list)->fd == fd)
	{
		ft_strdel(&((*f_list)->content));
		tmp = (*f_list)->next;
		free(*f_list);
		*f_list = tmp;
	}
	else
		while (curr->next)
		{
			tmp = curr->next;
			if (tmp->fd == fd)
			{
				ft_strdel(&(tmp->content));
				curr->next = tmp->next;
				free(tmp);
				break ;
			}
			curr = tmp;
		}
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*f_list;
	char			buf[BUFF_SIZE + 1];
	ssize_t			ret;
	t_file			*file;
	size_t			i;

	if (fd < 0 || !line || !(*line = ft_strnew(0))
	|| read(fd, buf, 0) < 0 || !(file = ft_get_file(&f_list, fd)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(file->content = ft_strjoin_and_free(file->content, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	i = ft_strchrcpy(line, file->content, 10);
	if (ret < BUFF_SIZE && !ft_strlen(file->content))
	{
		ft_fddel(&f_list, fd);
		return (0);
	}
	file->content = ft_cut_str(file->content, i);
	return (1);
}
