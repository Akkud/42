/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:09:59 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/15 18:51:19 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len2;

	len2 = ft_strlen(needle);
	if (!len2)
		return ((char*)haystack);
	if (*haystack)
		while (len-- >= len2 && *haystack)
			if (*haystack && !ft_memcmp(haystack++, needle, len2))
				return ((char*)--haystack);
	return (NULL);
}
