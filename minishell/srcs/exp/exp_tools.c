/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:55:00 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:55:01 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	exp_substitute(t_exp *exp, char *str)
{
	char	*res;

	if ((!exp->res && !(res = ft_strdup(str)))
	|| (exp->res && !(res = ft_strjoin(exp->res, str))))
		ft_ex(NULL, "cannot allocate memory\n");
	free(exp->res);
	exp->res = res;
}

void	init_exp(t_exp *exp)
{
	ft_bzero(exp->buf, EXP_BSIZE);
	exp->i = 0;
	exp->quote = 0;
	exp->bs = 0;
	exp->param = NULL;
	exp->word = NULL;
	exp->res = NULL;
}

void	free_exp_content(t_exp *exp)
{
	ft_strdel(&exp->param);
	ft_strdel(&exp->word);
	ft_strdel(&exp->res);
}

void	exp_flush_buf(t_exp *exp, char **str)
{
	char	*tmp;

	if (!str || !*str)
	{
		if (!(*str = ft_strdup(exp->buf)))
			ft_ex(NULL, "cannot allocate memory\n");
		ft_bzero(exp->buf, exp->i);
		exp->i = 0;
		return ;
	}
	tmp = *str;
	if (!(*str = ft_strjoin(*str, exp->buf)))
		ft_ex(NULL, "cannot allocate memory\n");
	free(tmp);
	ft_bzero(exp->buf, exp->i);
	exp->i = 0;
}

void	exp_add_to_buf(t_exp *exp, char **str, char **res)
{
	if (exp->i >= EXP_BSIZE - 1)
		exp_flush_buf(exp, res);
	exp->buf[exp->i] = **str;
	(*str)++;
	exp->i++;
}
