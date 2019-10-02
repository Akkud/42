/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:06:58 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:07:01 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_acl(char *file)
{
	acl_t	acl;

	if (!(acl = acl_get_file(file, ACL_TYPE_EXTENDED)))
		return (0);
	acl_free(acl);
	return (1);
}
