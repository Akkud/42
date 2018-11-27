/* ************************************************************************** */                                     
/*                                                                            */                                     
/*                                                        :::      ::::::::   */                                     
/*   get_next_line.h                                    :+:      :+:    :+:   */                                     
/*                                                    +:+ +:+         +:+     */                                     
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */                                     
/*                                                +#+#+#+#+#+   +#+           */                                     
/*   Created: 2018/08/29 18:39:23 by pacharbo          #+#    #+#             */                                     
/*   Updated: 2018/08/29 21:37:27 by pacharbo         ###   ########.fr       */                                     
/*                                                                            */                                     
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 13

typedef struct		s_list
{
	char		*content;
	int		fd;
	struct s_list	*next;
}		t_list;


