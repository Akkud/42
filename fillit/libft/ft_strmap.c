/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:02:18 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/15 20:25:50 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ret;

	if (!s)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s))) || s == NULL)
		return (NULL);
	ret = str;
	while (*s)
		*str++ = f(*s++);
	str = NULL;
	return (ret);
}
