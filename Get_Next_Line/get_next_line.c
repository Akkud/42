/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:38:19 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/30 18:12:25 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_list(char **str, t_list *lst, int fd)
{
	t_list	*alst;

	alst = lst;
	if (fd < 0)
		return (-1);
	while (fd != alst->fd)
	{
		if (alst->next)
			alst = alst->next;
		else
			return (1);
	}
	if (alst->content)
	{
		if (!(*str = ft_strnew(ft_strlen(alst->content))))
			return (-1);
		ft_strcpy(*str, alst->content);
		ft_strdel(&(alst->content));
	}
	return (1);
}

int		readqll(char **str, int fd)
{
	int		lu;
	char	tmp[BUFF_SIZE + 1];

	lu = 1;
	if (!*str)
		if (!(*str = ft_strnew(1)))
			return (-1);
	while (!ft_strchr(*str, 10) && lu > 0)
	{
		lu = read(fd, tmp, BUFF_SIZE);
		tmp[BUFF_SIZE] = '\0';
		if (!(*str = ft_strjoin((const char*)*str, tmp)))
			return (-1);
	}
	if (lu == 0)
		return (0);
	return (1);
}

int		last_ft(char *tmp, t_list *lst, int fd)
{
	t_list	*alst;

	alst = lst;
	while (fd != alst->fd)
	{
		if (alst->next)
			alst = alst->next;
		else
		{
			if (!(alst->next = (t_list*)malloc(sizeof(t_list))))
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

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	char			*str;
	char			*tmp;
	int				lu;

	if (!lst)
		if (!(lst = (t_list*)malloc(sizeof(t_list))))
			return (-1);
	lst->next = NULL;
	if (check_list(&str, lst, fd) < 0)
		return (-1);
	if ((lu = readqll(&str, fd)) < 0)
		return (-1);
	tmp = ft_memccpy(*line, str, 10, ft_strlen(str));
	*tmp = '\0';
	tmp = ft_strdup(ft_strchr((const char*)str, 10));
	//line[0][ft_strchr((const char*)*line, 10) - *line] = '\0';
	ft_strdel(&str);
	if (tmp)
		if (*tmp)
			return (last_ft(tmp, lst, fd) < 0 ? -1 : 1);
	if (!tmp && !lu)
		return (0);
	return (1);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char *line;

	(void)ac;
	line = ft_strnew(99999);
	fd = open(av[1], O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("ret = %d\nline = %s\n", ret, line);
	}
	return (0);
}
