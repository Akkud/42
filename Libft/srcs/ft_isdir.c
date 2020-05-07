/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:12:11 by pacharbo          #+#    #+#             */
/*   Updated: 2020/04/23 06:05:35 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isdir(char *path)
{
	DIR	*dir;

	if (!path)
		return (0);
	if ((dir = opendir(path)))
	{
		closedir(dir);
		return (1);
	}
	return (0);
}
