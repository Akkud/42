/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:55:27 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:57:13 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*resolve_parameter(t_msh *data, char *str)
{
	int		i;
	char	*res;

	i = -1;
	if (!(ft_strlen(str) == 1 && (ft_strchr("@*#?-$!", *str)
	|| ft_isdigit(*str)))
	&& !ft_isname(str))
		return (NULL);
	if ((res = ft_getenv(data->env, str))
	&& !(res = ft_strdup(res)))
		ft_ex(NULL, "cannot allocate memory\n");
	if (!res && !(res = ft_strnew(0)))
		ft_ex(NULL, "cannot allocate memory\n");
	return (res);
}
