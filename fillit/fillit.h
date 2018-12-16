/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:38:53 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/13 19:07:09 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include "libft/includes/libft.h"
# include <fcntl.h>

int		ft_read(char *av, char ***tab);
int		read_main(char *av, char ***tab);
int		checki_breeki(char **tab);
int		check_sharps(char **tab, int x, int y);
int		check_tetrucs(char **tab);

#endif
