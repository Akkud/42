/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:35:51 by guaubret          #+#    #+#             */
/*   Updated: 2018/11/16 18:05:47 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	c1 = *s1;
	c2 = *s2;
	return (c1 - c2);
}
