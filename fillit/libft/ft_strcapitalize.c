/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:52:14 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/18 21:59:24 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if ((!i || !ft_isalnum(str[i - 1])) && ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
		else if ((i > 0 && ft_isalnum(str[i - 1])) && ft_isupper(str[i]))
			str[i] = ft_tolower(str[i]);
	return (str);
}
