/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:51:04 by pacharbo          #+#    #+#             */
/*   Updated: 2018/12/08 16:53:20 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	a;

	a = 0;
	if (!s)
		return ;
	while (s[a])
		ft_putchar_fd(s[a++], fd);
}
