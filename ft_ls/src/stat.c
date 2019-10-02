/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:09:26 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:09:27 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_get_linkname(char *path)
{
	char	*buf;
	char	*ret;
	ssize_t	res;

	if (!(buf = (char *)malloc(PATH_MAX))
	|| ((res = readlink((const char *)path, buf, PATH_MAX)) == -1))
		return (NULL);
	else
		buf[res] = 0;
	if (!(ret = ft_strdup(buf)))
		return (0);
	free(buf);
	return (ret);
}

static int		set_user_name(struct stat buf, t_lsfile *file)
{
	struct passwd	*uid;

	if ((uid = getpwuid(buf.st_uid)))
	{
		if (!(file->info->user_name = ft_strdup(uid->pw_name)))
			return (0);
	}
	else if (!(file->info->user_name = ft_itoa((int)buf.st_uid)))
		return (0);
	return (1);
}

static int		ft_auth(char type, t_lsfilestat *info, struct stat buf,
		char *path)
{
	info->aut[0] = type;
	info->aut[1] = buf.st_mode & S_IRUSR ? 'r' : '-';
	info->aut[2] = buf.st_mode & S_IWUSR ? 'w' : '-';
	info->aut[3] = buf.st_mode & S_IXUSR ? 'x' : '-';
	info->aut[4] = buf.st_mode & S_IRGRP ? 'r' : '-';
	info->aut[5] = buf.st_mode & S_IWGRP ? 'w' : '-';
	info->aut[6] = buf.st_mode & S_IXGRP ? 'x' : '-';
	info->aut[7] = buf.st_mode & S_IROTH ? 'r' : '-';
	info->aut[8] = buf.st_mode & S_IWOTH ? 'w' : '-';
	info->aut[9] = buf.st_mode & S_IXOTH ? 'x' : '-';
	if (buf.st_mode & S_ISUID)
		info->aut[3] = (info->aut[3] == 'x') ? 's' : 'S';
	if (buf.st_mode & S_ISGID)
		info->aut[6] = (info->aut[6] == 'x') ? 's' : 'S';
	if (buf.st_mode & S_ISVTX)
		info->aut[9] = (info->aut[9]) == 'x' ? 't' : 'T';
	if (get_acl(path))
		info->aut[10] = '+';
	if (!get_xattr(info, path))
		return (0);
	info->aut[11] = 0;
	return (1);
}

int				ft_store_file_stats(t_lsfile *file, struct stat buf,
		char *path)
{
	struct group	*gid;

	ft_strcpy(file->info->aut, "---------- ");
	if (!(gid = getgrgid(buf.st_gid))
	|| !(ft_auth(file->type, file->info, buf, path)))
		return (0);
	file->info->hardlink = buf.st_nlink;
	if (!set_user_name(buf, file))
		return (0);
	file->info->group_name = gid->gr_name;
	file->info->size = buf.st_size;
	file->info->date = buf.st_mtime;
	file->info->blocks = buf.st_blocks;
	file->info->major = 0;
	file->info->minor = 0;
	if (file->type == 'l' && !(file->info->symlink = ft_get_linkname(path)))
		return (0);
	if (file->type == 'c' || file->type == 'b')
	{
		file->info->major = ((unsigned int)buf.st_rdev >> 16) / 256;
		file->info->minor = ((unsigned int)buf.st_rdev << 16) >> 16;
	}
	return (1);
}
