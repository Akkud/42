/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:24:39 by guaubret          #+#    #+#             */
/*   Updated: 2019/01/10 20:11:21 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_tetris
{
	char			value;
	int				pos[2];
	int				bloc[3][2];
	int				xmax;
	char			duplicate;
	struct s_tetris	*next;
}				t_tetris;

int				ft_check_line(char *line, int i);
int				ft_check_pieces(char **tab);
int				read_main(char *file, char ***tab, int *dim);
void			ft_print_words_tables(char **tab);
t_tetris		*ft_store_piece(char **tab, int x, int y, int i);
int				check_place(char **square, int dim, int pos[2],
int bloc[3][2]);
int				ft_solve_main(char ***square, t_tetris *list, int dim);
int				ft_init_square(char ***square, int dim);
void			ft_free_list(t_tetris **list);
void			ft_free_tab(char ***tab);
void			ft_free_square(char ***square, int dim);
#endif
