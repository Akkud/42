/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:02 by pacharbo          #+#    #+#             */
/*   Updated: 2019/04/10 16:34:11 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	getflag(char **fmt, t_printf *data)
{
	int		a;
	char	flag[6];
	
	a = -1;
	ft_strcpy(flag, "#0-+ ");
	while (flag[++a])
		if (**fmt == flag[a])
		{
			if (data->flag == NULL && !(data->flag = strnew[5]))
				//exit();
			data->flag[a] = flag[a];
			a = -1;
			fmt[0]++;
		}
}

void	getfw(char **fmt, t_printf *data)
{
	if (!(**fmt >= '1' && **fmt <= '9'))
		return ;
		data->fw = ft_atoi(*fmt)
	while (**fmt >= '0' && **fmt <= '9')
		fmt[0]++;
}

void	getprec(char **fmt, t_printf *data)
{
	if (**fmt != '.')
		return ;
	fmt[0]++;
	data->pr = ft_atoi(*fmt)
	while (**fmt >= '0' && **fmt <= '9')
		fmt[0]++;
}

void	getlmod(char **fmt, t_printf *data)
{
	if (**fmt == 'h')
	{	
		if (++fmt[0] == 'h')
		{
			data->lmod = 1;
			fmt[0]++;
		}
		else
			data->lmod = 2;
	}
	if (**fmt == 'l')
	{	
		if (++fmt[0] == 'l')
		{
			data->lmod = 4;
			fmt[0]++;
		}
		else
			data->lmod = 3;
	}
	if (**fmt == 'L')
	{
		data->lmod = 5;
		fmt[0]++;
	}
}

int		getconv(char **fmt, t_printf *data)
{
	int		a;
	char	conv[15];

	ft_strcpy(conv, " diouxXcspfegb");
	a = 0;
	while (conv[++a])
		if (**fmt == conv[a])
		{
			data->conv = a;
			fmt[0]++;
			return (1);
		}
	return (0);
}
