/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:38:19 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/06 14:48:50 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

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
		if (!(*str = ft_strdup(alst->content)))
			return (-1);
		ft_strdel(&(alst->content));
	}
	return (1);
}

static int		readqll(char **str, int fd)
{
	int		lu;
	char	*tmp;
	char	*ptr;

	lu = 1;
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!*str)
		if (!(*str = ft_strnew(1)))
			return (-1);
	if (ft_strchr(*str, 10))
		return (0);
	while (!ft_strchr(*str, 10) && lu > 0)
	{
		lu = read(fd, tmp, BUFF_SIZE);
		tmp[lu] = '\0';
		ptr = *str;
		if (!(*str = ft_strjoin((const char*)*str, tmp)))
			return (-1);
		free(ptr);
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
	if (!(alst->content = ft_strdup((const char*)tmp)))
		return (-1);
	return (1);
}

static int		fr(char **s1, char **s2, char **s3)
{
	return (ft_iferrfree((void**)s1, (void**)s2, (void**)s3, 0));
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	char			*tmp;
	char			*str;

	str = NULL;
	if (check_list(&str, &lst, fd) < 0)
		return (-1);
	if ((readqll(&str, fd)) < 0)
		return (-1 + fr(&str, 0, 0));
	if (ft_strchr(str, 10))
	{
		if (!(*line = ft_strnew(ft_strchr(str, 10) - str)))
			return (-1 + fr(&str, line, 0));
		ft_strlcpy(*line, str, ft_strchr(str, 10) - str + 1);
		tmp = ft_strdup(ft_strchr((const char*)str, 10) + 1);
		if (last_ft(tmp, lst, fd) < 0)
			return (-1 + fr(&str, &tmp, line));
		return (1 + fr(&str, &tmp, 0));
	}
	if (!(*line = ft_strdup(str)))
		return (-1 + fr(&str, line, 0));
	if (*str)
		return (1 + fr(&str, 0, 0));
	return (fr(&str, 0, 0));
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
**	(void)fd2;
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
