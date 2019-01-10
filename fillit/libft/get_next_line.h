/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:50:46 by guaubret          #+#    #+#             */
/*   Updated: 2018/12/13 15:18:43 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# include "libft.h"

typedef struct	s_file
{
	char			*content;
	char			*beg;
	int				fd;
	struct s_file	*next;
}				t_file;
int				get_next_line(const int fd, char **line);

#endif
