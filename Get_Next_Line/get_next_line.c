/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:38:19 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/27 18:10:52 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_list(char **str, size_t fd)
{
	t_list	*alst;

	alst = lst;
	while (fd != alst->fd)
	{
		if (alst->(*next))
			alst = alst->next;
		else
		{
			if (!(alst->next = (t_list*)malloc(sizeof(t_list))))
				return (-1);
			alst = alst->next;
			alst->fd = fd;
		}
	}
	if (alst->(*content))
	{
		if (!(*str = ft_strnew(ft_strlen(alst->content))))
			return (-1);
		ft_strcpy(*str, alst->content);
		free(alst->content);
	}
	return (1);
}

int		readqll(char **str)
{
	int 	lu;
	char	tmp[BUFF_SIZE + 1];

	a = 0;
	lu = 1;
	if (!**str)
		if (!(*str = strnew(BUFF_SIZE)))
			return (-1);
	while (!ft_strchr(*str, 10) && lu)
	{
		lu = read(fd, tmp, BUFF_SIZE);
		tmp[BUFF_SIZE] = '\0';
		if (!(*str = ft_strjoin(str, tmp)))
			return (-1);
	}
	return (1);
}

int		last_ft(char **str)
{
	t_list	*alst;

	alst = lst;
	while (fd != alst->fd)
	{
		if (alst->(*next))
			alst = alst->next;
		else
		{
			if (!(alst->next = (t_list*)malloc(sizeof(t_list))))
				return (-1);
			alst = alst->next;
			alst->fd = fd;
		}
	}
	if (alst->(*content))
	{
		if (!(*str = ft_strnew(ft_strlen(alst->content))))
			return (-1);
		ft_strcpy(*str, alst->content);
		free(alst->content);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	char		*str;
	int		a;

	if (!lst)
		if (!(lst = (t_list*)malloc(sizeof(t_list))))
			return (-1);
	if (check_list(&str) < 0)
		return (-1);
	readqll(&str);
	memccpy(line, str, 10, ft_strlen(str));


}
