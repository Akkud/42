/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:02:32 by pacharbo          #+#    #+#             */
/*   Updated: 2018/11/07 22:03:53 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int c;

	c = 0;
	if (nb == 1 || nb == 0)
		return (nb);
	while (c < nb / 2 && c <= 46340)
	{
		if (c * c == nb)
			return (c);
		c++;
	}
	return (0);
}
