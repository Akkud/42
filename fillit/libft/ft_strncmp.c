/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:40:58 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/16 17:57:09 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	if (!*s1 || !*s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (n--)
		if (!*s1 || !*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return (0);
}
