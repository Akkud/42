/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:50:46 by guaubret          #+#    #+#             */
/*   Updated: 2018/12/04 17:02:58 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# include <fcntl.h>

typedef struct	s_file
{
	char			*content;
	int				fd;
	struct s_file	*next;
}				t_file;
int				get_next_line(const int fd, char **line);

#endif
