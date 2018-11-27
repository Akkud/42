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

int		check_list(char *str)
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
				return (0);
			alst = alst->next;
			alst->fd = fd;
		}
	}
	if (alst->content)
	{
		str = alst->content;
		free(alst->content);
	}
	return (1);
}

int		readqll(char *str)
{
	int 	a;
	char	tmp[BUFF_SIZE + 1];

	a = 0;
	while (!ft_strchr(str, 10))
	{
		read(fd, tmp, BUFF_SIZE);
		if (str)
		{
			if (!(ft_strjoin(str, tmp)))
				return (0);
		}
		else
			ft_strcpy(str, tmp);
	}

}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	char	*str;
	int		a;

	if (!lst)
		if (!(lst = (t_list*)malloc(sizeof(t_list))))
			return (-1);
	if (!(str = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!check_list(str))
		return (-1);
	if (!str
	if (strchr(str, 10))





}
