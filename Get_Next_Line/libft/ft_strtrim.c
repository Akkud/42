/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:27:21 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 16:58:09 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	a;
	unsigned int	start;
	unsigned int	len;

	a = 0;
	if (!s)
		return (0);
	if (!s[0])
		return (ft_strnew(0));
	while (s[a] && (s[a] == 32 || s[a] == '\n' || s[a] == '\t'))
		a++;
	if (!s[a])
		return (ft_strnew(1));
	start = a;
	a = ft_strlen((char*)s) - 1;
	while (s[a] == 32 || s[a] == '\n' || s[a] == '\t')
		a--;
	len = a - start + 1;
	return (ft_strsub(s, start, len));
}
