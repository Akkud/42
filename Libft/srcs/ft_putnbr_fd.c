/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:56:12 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:13:23 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			if (n < (-9))
				ft_putnbr_fd(n / 10 * (-1), fd);
			ft_putchar_fd(n % 10 * (-1) + 48, fd);
		}
		else
		{
			if (n > 9)
				ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + 48, fd);
		}
	}
}
