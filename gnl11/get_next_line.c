/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:42:10 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 18:58:05 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

int		get_next_line(int fd, char **line)
{
	static char		*tab[OPEN_MAX];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				nblu;

	nblu = 0;
	if (!line || (read(fd, NULL, 0) < 0))
		return (-1);
	if (!tab[fd] || !CHR)
		while ((!tab[fd] || !CHR) && (nblu = (read(fd, buf, BUFF_SIZE))) > 0)
		{
			buf[nblu] = '\0';
			tmp = tab[fd] ? tab[fd] : NULL;
			if (!(tab[fd] = tab[fd] ? ft_strjoin(tab[fd], buf) : ft_strdup(buf)))
				return (-1);
			tmp ? free(tmp) : 0;
		}
	if (!nblu && (!tab[fd] || !tab[fd][0]))
		return ((*line = ft_strnew(0)) ? 0 : -1);
	if (!(*line = CHR ? SUB : ft_strdup(tab[fd])))
		return (-1);
	tmp = CHR ? ft_strdup(CHR + 1) : NULL;
	free(tab[fd]);
	return ((tab[fd] = tmp) ? 1 : 1);
}
