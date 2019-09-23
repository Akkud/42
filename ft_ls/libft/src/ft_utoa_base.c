/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:50:30 by guaubret          #+#    #+#             */
/*   Updated: 2019/05/20 19:50:40 by guaubret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(uintmax_t nbr, char *base)
{
	unsigned int	base_l;
	char			*str;

	base_l = ft_strlen(base);
	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = base[nbr % base_l];
	if (nbr >= base_l
	&& !(str = ft_strclnjoin(ft_utoa_base((nbr /= base_l), base), str)))
		return (NULL);
	return (str);
}
