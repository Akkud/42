/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:18:53 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:48:55 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Replaces the first occurence of rem in str by rep if set.
** If rep is not set, simply removes the first occurence of rem in str.
*/

char		*ft_strrep(char *str, char *rem, char *rep)
{
	char		*ret;
	char		*occurence;
	size_t		replen;

	replen = rep ? ft_strlen(rep) : 0;
	if (!str || !rem)
		return (0);
	if (!(occurence = ft_strstr(str, rem)))
		return (str);
	if (!(ret = ft_strnew(ft_strlen(str) - ft_strlen(rem) + replen)))
		return (0);
	ft_strncpy(ret, str, occurence - str);
	if (replen)
		ft_strcat(ret, rep);
	ft_strcat(ret, occurence + ft_strlen(rem));
	return (ret);
}
