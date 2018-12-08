/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:26:20 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 18:49:27 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 17
# define CHR ft_strchr(tab[fd], '\n')
# define SUB ft_strsub(tab[fd], 0, (size_t)(CHR - tab[fd]))
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int				get_next_line(const int fd, char **line);
#endif
