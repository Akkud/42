/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclnsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:49:45 by guaubret          #+#    #+#             */
/*   Updated: 2019/05/20 19:49:49 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strclnsub(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ret;
	char	*tmp;

	tmp = s;
	if (!(str = ft_strnew(len)) || !tmp)
		return (NULL);
	tmp += start;
	ret = str;
	while (*tmp && len--)
		*str++ = *tmp++;
	*str = '\0';
	free(s);
	return (ret);
}
