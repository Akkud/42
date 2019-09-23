#include "ft_ls.h"

long long		*ft_rev_merge(long long *tab, int l, int r, int m)
{
	long long	*tmp;
	int			i;
	int			oldm;
	int			oldl;

	if (!(tmp = (long long*)malloc(sizeof(long long) * (r - l + 1))))
		return (0);
	i = 0;
	m = (r - l) / 2 + l + 1;
	oldm = m;
	oldl = l;
	while (i + oldl <= r)
		if (l < oldm && m <= r)
		{
			if (tab[l] <= tab[m])
				tmp[i++] = tab[l++];
			else
				tmp[i++] = tab[m++];
		}
		else if (m > r)
			tmp[i++] = tab[l++];
		else
			tmp[i++] = tab[m++];
	return (tmp);
}

long long		*ft_merge(long long *tab, int l, int r, int m)
{
	long long	*tmp;
	int			i;
	int			oldm;
	int			oldl;

	if (!(tmp = (long long*)malloc(sizeof(long long) * (r - l + 1))))
		return (0);
	i = 0;
	m = (r - l) / 2 + l + 1;
	oldm = m;
	oldl = l;
	while (i + oldl <= r)
		if (l < oldm && m <= r)
		{
			if (tab[l] > tab[m])
				tmp[i++] = tab[l++];
			else
				tmp[i++] = tab[m++];
		}
		else if (m > r)
			tmp[i++] = tab[l++];
		else
			tmp[i++] = tab[m++];
	return (tmp);
}

int				ft_fill(long long *tab, long long *tmp, int l, int r)
{
	int		i;

	i = -1;
	if (!tmp)
		return (0);
	while (++i <= r - l)
		tab[i + l] = tmp[i];
	free(tmp);
	return (1);
}

int				ft_nmsort(long long *tab, int l, int r, int order)
{
	int		m;

	if (l < r)
	{
		m = (r - l) / 2 + l;
		if (!(ft_nmsort(tab, l, m, order))
		|| !(ft_nmsort(tab, m + 1, r, order)))
			return (0);
		if (!order)
			if (!ft_fill(tab, (ft_merge(tab, l, r, m)), l, r))
				return (0);
		if (order)
			if (!ft_fill(tab, (ft_rev_merge(tab, l, r, m)), l, r))
				return (0);
	}
	return (1);
}
