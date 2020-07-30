/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <pacharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 07:47:32 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/21 07:47:37 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_del_tab(void **tab)
{
	char	**target;
	int		i;

	i = 0;
	if (!tab || !*tab)
	{
		free(tab);
		return ;
	}
	target = (char **)tab;
	while (target[i])
		ft_strdel(&target[i++]);
	free(target);
}
