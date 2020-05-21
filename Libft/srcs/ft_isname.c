/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:47:48 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:47:50 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isname(char *str)
{
	if (ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isalnum((int)*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}
