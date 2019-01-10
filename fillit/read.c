/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:23:16 by guaubret          #+#    #+#             */
/*   Updated: 2019/01/10 20:06:39 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_find_duplicate(t_tetris *list, t_tetris *piece)
{
	int	i;

	while (list && list->value != piece->value)
	{
		i = -1;
		while (++i < 3)
		{
			if (!(list->bloc[i][0] == piece->bloc[i][0]
			&& list->bloc[i][1] == piece->bloc[i][1]))
				break ;
			if (i == 2)
				piece->duplicate = list->value;
		}
		list = list->next;
	}
}

static int		ft_sqrt_up(int x)
{
	int	i;

	i = 0;
	while (i * i < x)
		i++;
	return (i);
}

void			ft_free_tab(char ***tab)
{
	char	**ptr;

	ptr = *tab;
	while (*ptr)
		ft_strdel(&(*ptr++));
	if (*tab)
		free(*tab);
}

static char		**ft_tabdup_free(char ***tab, char *line)
{
	char	**ret;
	char	**ptr;
	char	**tmp;
	size_t	tab_len;

	tab_len = 0;
	if (**tab)
	{
		ptr = *tab;
		while (*ptr++)
			tab_len = ptr - *tab;
	}
	if (!(ret = (char**)malloc(sizeof(char*) * (tab_len + 2))))
		return (NULL);
	tmp = ret;
	ptr = *tab;
	while (*ptr)
		if (!(*tmp++ = ft_strdup(*ptr++)))
			return (NULL);
	if (!(*tmp++ = ft_strdup(line)))
		return (NULL);
	*tmp = NULL;
	ft_free_tab(tab);
	free(line);
	return (ret);
}

static void		bloc_assign(int *i, int pos[3][2], t_tetris *new)
{
	if (pos[*i][1] > new->xmax)
		new->xmax = pos[*i][1];
	new->bloc[*i][0] = pos[*i][0];
	new->bloc[*i][1] = pos[*i][1];
	(*i)++;
}

static int		ft_tetrisadd(t_tetris **list, int pos[3][2], char letter)
{
	t_tetris	*piece;
	t_tetris	*new;
	int			i;

	piece = *list;
	while (piece && piece->next)
		piece = piece->next;
	if (!(new = (t_tetris*)malloc(sizeof(t_tetris))))
		return (0);
	new->pos[0] = 0;
	new->pos[1] = 0;
	i = 0;
	new->xmax = pos[i][1];
	while (i < 3)
		bloc_assign(&i, pos, new);
	new->duplicate = 0;
	new->value = letter;
	new->next = NULL;
	if (piece)
		piece->next = new;
	else
		*list = new;
	ft_find_duplicate(*list, new);
	return (1);
}

t_tetris		*ft_store_piece(char **tab, int x, int y, int i)
{
	t_tetris	*list;
	int			pos_ref[2];
	int			pos[3][2];
	int			flag;
	char		letter;

	flag = 0;
	list = NULL;
	letter = 'A';
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (flag && tab[y][x] == '#')
			{
				pos[i][0] = y - pos_ref[0];
				pos[i][1] = x - pos_ref[1];
				i++;
			}
			else if (tab[y][x] == '#')
			{
				pos_ref[0] = y;
				pos_ref[1] = x;
				flag = 1;
			}
			x++;
		}
		if ((y + 2) % 5 == 0)
		{
			if (!(ft_tetrisadd(&list, pos, letter++)))
				return (NULL);
			flag = 0;
			i = 0;
		}
		y++;
	}
	return (list);
}

int				read_main(char *file, char ***tab, int *dim)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	i = 1;
	if (!(*tab = (char**)malloc(sizeof(char*))))
		return (0);
	fd = open(file, O_RDONLY);
	**tab = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
		if ((!ft_check_line(line, i++))
		|| (!(*tab = ft_tabdup_free(tab, line))))
		{
			free(line);
			return (0);
		}
	free(line);
	close(fd);
	if ((!ret && (i % 5) != 0) || ret || !ft_check_pieces(*tab))
		return (0);
	*dim = ft_sqrt_up(i / 5 * 4);
	return (1);
}
