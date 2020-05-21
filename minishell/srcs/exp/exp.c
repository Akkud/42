/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:54:50 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:56:48 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int		exp_main(t_msh *data, char **word, int assign)
{
	t_exp		exp;
	int			ret;

	init_exp(&exp);
	exp.assign = assign;
	if (assign)
		find_tilde_exp_assign(data, word, exp);
	else
		find_tilde_exp(data, word, exp);
	ft_bzero(exp.buf, EXP_BSIZE);
	if ((ret = parse_param_exp(data, word, exp)) < 0)
		return (ret);
	return (1);
}
