/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:26 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/10 18:29:49 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 50
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct		s_printf
{
/*	union				arg
**	{
**		int				dic;
**		unsigned int	ouxx;
//		double			eg;
**		wint_t			lc;
**		const char		*s;
**		const wchar_t	*ls;
**		void			*p;
	};
*/
	void			*arg;	// NULL puis l'argument
	int				conv;	// 0 puis l'ID de la conversion : diouxXcspfegb (1 - 13)
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

#endif
