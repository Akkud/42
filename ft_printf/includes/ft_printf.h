/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:26 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/24 16:32:30 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 50
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../Libft/includes/libft.h"
# include <stdio.h>

typedef	struct		s_printf
{
	int				conv;	// 0 puis l'ID de la conversion : diouxXcspfegb (0 - 12)
	char			*flag;	// NULL puis strnew[5] si flag present
	int				fw;		// 0 puis la valeur du field width
	int				pr;		// -1 puis la valeur de la precision
	int				lmod;	// 0 puis l'ID du length modifier : hh/h/l/ll/L (1 - 5)
	char			*res;	// NULL puis le resultat
}					t_printf;

/*	Si # et conv == o -> fw = -1
**			conv == x -> fw = -2
**
**
**
*/

int				getflag(char **fmt, t_printf *data);
void			getfw(char **fmt, t_printf *data);
void			getprec(char **fmt, t_printf *data);
void			getlmod(char **fmt, t_printf *data);
int				getconv(char **fmt, t_printf *data);
int				conv_main(va_list ap, t_printf *data);

#endif
