/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:55:35 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/15 18:14:04 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*ret;

	ret = dst;
	while (*src && len)
	{
		*dst++ = *src++;
		len--;
	}
	if (!len)
		return (ret);
	while (len--)
		*dst++ = '\0';
	return (ret);
}
