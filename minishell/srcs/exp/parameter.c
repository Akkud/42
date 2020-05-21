/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:55:19 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:57:39 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int		parse_simple_parameter(t_exp *exp, char **str, char **param)
{
	while (**str && (ft_isalnum((int)**str) || **str == '_'))
		exp_add_to_buf(exp, str, param);
	if (!exp->i)
	{
		(*str)--;
		exp_add_to_buf(exp, str, &exp->res);
		exp_flush_buf(exp, &exp->res);
		return (0);
	}
	exp_flush_buf(exp, param);
	return (1);
}

void	special_parameter(char **str, char **param)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *str;
	if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
		{
			i++;
			(*str)++;
		}
		if (!(*param = ft_strndup(tmp, i)))
			ft_ex(NULL, "cannot allocate memory\n");
	}
	else
	{
		if (!(*param = ft_strndup(*str, 1)))
			ft_ex(NULL, "cannot allocate memory\n");
		(*str)++;
	}
}

int		simple_param_exp(t_msh *data, t_exp *exp, char **str)
{
	char	*param;

	param = NULL;
	(*str)++;
	if (**str && (ft_strchr("@*#?-$!", **str) || ft_isdigit(**str)))
		special_parameter(str, &param);
	else if (!parse_simple_parameter(exp, str, &param))
		return (0);
	if (!(exp->param = resolve_parameter(data, param)))
		return (-1);
	free(param);
	exp_substitute(exp, exp->param);
	ft_strdel(&exp->param);
	return (0);
}

int		param_dispatch(t_msh *data, t_exp *exp, char **str)
{
	if (**str == '$' && exp->quote != 1)
	{
		exp_flush_buf(exp, &exp->res);
		return (simple_param_exp(data, exp, str));
	}
	else if (ft_strchr("\'\"\\", **str))
	{
		if (**str == '\'' && exp->quote < 2)
			exp->quote = exp->quote == 1 ? 0 : 1;
		else if (**str == '\"' && exp->quote != 1)
			exp->quote = exp->quote == 2 ? 0 : 2;
		else if (**str == '\\' && exp->quote != 1)
			exp->bs = 2;
	}
	return (1);
}

int		parse_param_exp(t_msh *data, char **word, t_exp exp)
{
	char	*str;
	int		ret;

	if (!word || !(str = *word))
		return (0);
	ret = 0;
	while (*str)
	{
		if ((!exp.bs && ft_strchr("\'\"\\$", *str)
		&& (ret = param_dispatch(data, &exp, &str)) < 0) || !*str)
			break ;
		if (exp.bs || (*str != '$'))
			exp_add_to_buf(&exp, &str, &exp.res);
		if (exp.bs)
			exp.bs--;
	}
	if (ret >= 0)
	{
		exp_flush_buf(&exp, &exp.res);
		free(*word);
		if (!(*word = ft_strdup(exp.res)))
			ft_ex(NULL, "cannot allocate memory\n");
	}
	free_exp_content(&exp);
	return (ret);
}
