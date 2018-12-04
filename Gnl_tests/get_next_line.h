/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:26:20 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/04 19:39:01 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 11000

# include <fcntl.h>

typedef struct	s_gnl
{
	char			*content;
	int				fd;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
