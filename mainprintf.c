/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:44:43 by pacharbo          #+#    #+#             */
/*   Updated: 2019/09/11 17:55:11 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

int				main(void)
{
//	char			*str = "test";
//	long double		eflot = 54645.003;
//	char			c = 'e';
//	int				nb = 6548321;

//	ft_printf("coucou");
//	ft_printf("%s", str);
//	printf("printf : [%s]", str);
//	ft_printf("% 0+-#10.5hhs", str);
//	ft_printf("efl = %d\n", -3);
//	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", '1', '2', '3', '4', '5', '6', '7', '8', '9', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\n', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\n', '1', '2', '3', '4', '5', '6', '7');
//	ft_printf("efl = %lld\n", LLONG_MIN - 1);
//	printf("vre = %lld\n", LLONG_MIN - 1);
//	ft_printf("%hu, %hu\n", (unsigned short)0, (unsigned short)USHRT_MAX);
//	printf("%hu, %hu\n", (unsigned short)0, (unsigned short)USHRT_MAX);
//	ft_printf("%hhu, %hhu\n",(unsigned char)0, (unsigned char)(UCHAR_MAX + 42));
//	printf("%hhu, %hhu\n", (unsigned char)0, (unsigned char)(UCHAR_MAX + 42));
//	ft_printf("{%3c}\n", 0);
//	printf("{%3c}\n", 0);
//	ft_printf("{%030x}\n", 0xFFFF);
//	printf("{%030x}\n", 0xFFFF);
//	ft_printf("%o, %ho, %hho\n", 42, 44300, 100000);
//	ft_printf("%s", 42);
//	ft_printf("%d\n", "coucou");
//	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-','.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';','<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
//	ft_printf("%c\n", ' ');
	return (0);
}

/*
**	// Main de test pour les leaks.
**int				main(void)
**{
**	ft_printf("\n");
**	ft_printf("%%\n");
**	ft_printf("%d\n", 42);
**	ft_printf("%d%d\n", 42, 41);
**	ft_printf("%d%d%d\n", 42, 43, 44);
**	ft_printf("%ld\n", 2147483647);
**	ft_printf("%lld\n", 9223372036854775807);
**	ft_printf("%x\n", 505);
**	ft_printf("%X\n", 505);
**	ft_printf("%p\n", &ft_printf);
**	ft_printf("%20.15d\n", 54321);
**	ft_printf("%-10d\n", 3);
**	ft_printf("% d\n", 3);
**	ft_printf("%+d\n", 3);
**	ft_printf("%010d\n", 1);
**	ft_printf("%hhd\n", 0);
**	ft_printf("%jd\n", 9223372036854775807);
**	ft_printf("%zd\n", 4294967295);
**	ft_printf("%\n");
**	ft_printf("%U\n", 4294967295);
**	ft_printf("%u\n", 4294967295);
**	ft_printf("%o\n", 40);
**	ft_printf("%%#08x\n", 42);
**	ft_printf("%x\n", 1000);
**	ft_printf("%#X\n", 1000);
**	ft_printf("%s\n", NULL);
**	ft_printf("%S\n", L"ݗݜशব");
**	ft_printf("%s%s\n", "test", "test");
**	ft_printf("%s%s%s\n", "test", "test", "test");
**	ft_printf("%C\n", 15000);
**	return (0);
**}
*/
