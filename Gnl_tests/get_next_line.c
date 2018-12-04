/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:38:19 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/04 20:22:37 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int		check_list(char **str, t_gnl **lst, int fd)
{
	t_gnl	*alst;

	if (!*lst)
	{
		if (!(*lst = (t_gnl*)malloc(sizeof(t_gnl))))
			return (-1);
		(*lst)->next = NULL;
		(*lst)->content = NULL;
	}
	alst = *lst;
	if (fd < 0)
		return (-1);
	while (fd != alst->fd)
		if (alst->next)
			alst = alst->next;
		else
			return (1);
	if (alst->content)
	{
		if (!(*str = ft_strnew(ft_strlen(alst->content))))
			return (-1);
		ft_strcpy(*str, alst->content);
		ft_strdel(&(alst->content));
	}
	return (1);
}

static int		readqll(char **str, int fd)
{
	int		lu;
	char	tmp[BUFF_SIZE + 1];

	lu = 1;
	if (!*str)
		if (!(*str = ft_strnew(1)))
			return (-1);
	if (ft_strchr(*str, 10))
		return (0);
	while (!ft_strchr(*str, 10) && lu > 0)
	{
		lu = read(fd, tmp, BUFF_SIZE);
		tmp[lu] = '\0';
		if (!(*str = ft_strjoin((const char*)*str, tmp)))
			return (-1);
	}
	if (lu == 0)
		return (0);
	return (lu == -1 ? -1 : 1);
}

static int		last_ft(char *tmp, t_gnl *lst, int fd)
{
	t_gnl	*alst;

	alst = lst;
	if (!tmp[0])
		return (1);
	while (fd != alst->fd)
	{
		if (alst->next)
			alst = alst->next;
		else
		{
			if (!(alst->next = (t_gnl*)malloc(sizeof(t_gnl))))
				return (-1);
			alst = alst->next;
			alst->fd = fd;
			alst->next = NULL;
		}
	}
	if (!(alst->content = ft_strnew(ft_strlen(tmp))))
		return (-1);
	ft_strcpy(alst->content, tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	int				lu;
	char			*tmp;
	char			*str;

	str = NULL;
	if (check_list(&str, &lst, fd) < 0)
		return (-1);
	if ((lu = readqll(&str, fd)) < 0)
		return (-1);
	if (ft_strchr(str, 10))
	{
		if (!(*line = ft_strnew(ft_strchr(str, 10) - str)))
			return (-1);
		ft_strlcpy(*line, str, ft_strchr(str, 10) - str + 1);
		tmp = ft_strdup(ft_strchr((const char*)str, 10) + 1);
		if (last_ft(tmp, lst, fd) < 0)
			return (-1);
		return (1 + ft_iferrfree((void**)&str, (void**)&tmp, 0, 0));
	}
	if (!(*line = ft_strdup(str)))
		return (-1);
	if (*str)
		return (1);
	return (0);
}

/*
**#include <stdio.h>
**
**int				main(int ac, char **av)
**{
**	int		fd;
**	int		fd2;
**	int		ret;
**	int		ret2;
**	char	*line;
**
**	(void)ac;
**	line = ft_strnew(99999);
**	fd = open(av[1], O_RDONLY);
**	fd2 = open(av[2], O_RDONLY);
**	ret = 1;
**	ret2 = 1;
**	while (ret > 0 && ret2 > 0)
**	{
**		ret = get_next_line(fd, &line);
**		printf("%s\n", line);
**		ret2 = get_next_line(fd2, &line);
**		printf("%s\n", line);
**	}
**	return (0);
**}
*/
