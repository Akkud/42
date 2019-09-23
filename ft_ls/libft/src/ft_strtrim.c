/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:44:57 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/15 20:42:18 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		size;
	char		*str;
	char const	*ptr;

	size = 0;
	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
		s++;
	if (!*s)
		return (ft_strnew(1));
	ptr = s;
	while (*s++)
		size++;
	s -= 2;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s--)
		size--;
	if (!(str = ft_strsub(ptr, 0, size)))
		return (NULL);
	return (str);
}
