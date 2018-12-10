/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:42:10 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/10 19:29:53 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

char	*f(char *tb, int coucou)
{
	if (coucou == 1)
		return (ft_strchr(tb, '\n'));
	else
		return (ft_strsub(tb, 0, (size_t)(f(tb, 1) - tb)));
}

int		get_next_line(int fd, char **line)
{
	static char		*tb[OPEN_MAX];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				lu;

	lu = 0;
	if (!line || (read(fd, NULL, 0) < 0))
		return (-1);
	while ((!tb[fd] || !f(tb[fd], 1)) && (lu = (read(fd, buf, BUFF_SIZE))) > 0)
	{
		buf[lu] = '\0';
		tmp = tb[fd] ? tb[fd] : NULL;
		if (!(tb[fd] = tb[fd] ? ft_strjoin(tb[fd], buf) : ft_strdup(buf)))
			return (-1);
		tmp ? free(tmp) : 0;
	}
	if (!lu && (!tb[fd] || !tb[fd][0]))
		return ((*line = ft_strnew(0)) ? 0 : -1);
	if (!(*line = f(tb[fd], 1) ? f(tb[fd], 6849) : ft_strdup(tb[fd])))
		return (-1);
	if (!(tmp = f(tb[fd], 1) ? ft_strdup(f(tb[fd], 1) + 1) : (char*)1))
		return (-1);
	tmp = tmp == (char*)1 ? NULL : tmp;
	free(tb[fd]);
	return ((tb[fd] = tmp) ? 1 : 1);
}
/*
**#include <stdio.h>
**#include <fcntl.h>
**
**int		main(int argc, char **argv)
**{
**	char	*line;
**	int		ret;
**	int		fd;
**
**	(void)argc;
**	ret = 1;
**	fd = open(argv[1], O_RDONLY);
**	while (ret > 0)
**	{
**		ret = get_next_line(0, &line);
**		printf("%s\n", line);
**	}
**	close(fd);
**	return (0);
**}
*/
