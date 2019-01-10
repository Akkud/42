/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:29:15 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/15 20:28:53 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ret;

	if (!(str = ft_strnew(len)) || !s)
		return (NULL);
	s += start;
	ret = str;
	while (*s && len--)
		*str++ = *s++;
	*str = '\0';
	return (ret);
}
