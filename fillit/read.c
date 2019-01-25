/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guaubret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:23:16 by guaubret          #+#    #+#             */
/*   Updated: 2019/01/25 20:11:13 by pacharbo         ###   ########.fr       */
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

t_tetris		*ft_store_piece(char **tab, int y)
{
	t_tetris	*list;
	int			pos[3][2];
	char		letter;

	list = NULL;
	letter = 'A';
	while (tab[y])
	{
		if (y % 5 == 0)
		{
			ft_find_blocs(tab + y, pos);
			if (!(ft_tetrisadd(&list, pos, letter++)))
				return (NULL);
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
	if ((fd = check_fd(file)) < 0)
		return (0);
	if (!(*tab = (char**)malloc(sizeof(char*))))
		return (0);
	**tab = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
		if ((!ft_check_line(line, i++))
		|| (!(*tab = ft_tabdup_free(tab, line))))
		{
			free(line);
			return (0);
		}
	free(line);
	if (close(fd) || i > 130)
		return (0);
	if ((!ret && (i % 5) != 0) || ret || !ft_check_pieces(*tab, -1))
		return (0);
	*dim = ft_sqrt_up(i / 5 * 4);
	return (1);
}
