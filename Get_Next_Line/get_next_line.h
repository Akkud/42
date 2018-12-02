/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:26:20 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/02 21:36:34 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}				t_list;

int				get_next_line(const int fd, char **line);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strchr(const char *str, int c);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *src);
long			ft_iferrfree(void **pt1, void **pt2, void **pt3, void **pt4);

#endif
