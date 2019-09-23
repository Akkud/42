#include "ft_ls.h"

char			*join_file_names(char *file_path, char *file_name, char **dest)
{
	char	*new;

	free(*dest);
	if (!(new = ft_strjoin(file_path, "/")))
		return (NULL);
	if (!(new = ft_strlclnjoin(new, file_name)))
		return (NULL);
	*dest = new;
	return (new);
}

static char		ft_get_file_type(struct stat buf)
{
	char	c;

	c = '?';
	c = (S_IFSOCK == (S_IFMT & buf.st_mode)) ? 's' : c;
	c = (S_IFREG == (S_IFMT & buf.st_mode)) ? '-' : c;
	c = (S_IFBLK == (S_IFMT & buf.st_mode)) ? 'b' : c;
	c = (S_IFDIR == (S_IFMT & buf.st_mode)) ? 'd' : c;
	c = (S_IFCHR == (S_IFMT & buf.st_mode)) ? 'c' : c;
	c = (S_IFIFO == (S_IFMT & buf.st_mode)) ? 'p' : c;
	c = (S_IFLNK == (S_IFMT & buf.st_mode)) ? 'l' : c;
	return (c);
}

static void		ft_info_setup(t_lsfile *file)
{
	if (file && file->info)
	{
		file->info->hardlink = 0;
		file->info->user_name = NULL;
		file->info->group_name = NULL;
		file->info->size = 0;
		file->info->date = 0;
		file->info->symlink = NULL;
		file->info->blocks = 0;
		file->info->xattr = NULL;
		file->info->xattr_size = 0;
		file->info->user_alloc = 0;
	}
}

int				ft_get_file_stats(t_lsfile *file)
{
	struct stat		buf;
	char			*path;

	path = NULL;
	if (!(file->info = (t_lsfilestat*)malloc(sizeof(t_lsfilestat))))
		return (0);
	ft_info_setup(file);
	if (file->path)
	{
		if (!(path = join_file_names(file->path, file->name, &path)))
			return (0);
	}
	else if (!(path = ft_strdup(file->name)))
		return (0);
	if (lstat(path, &buf) == -1
	|| !(file->type = ft_get_file_type(buf))
	|| !ft_store_file_stats(file, buf, path))
	{
		free(path);
		return (0);
	}
	free(path);
	return (1);
}
