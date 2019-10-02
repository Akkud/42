/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:06:48 by pacharbo          #+#    #+#             */
/*   Updated: 2019/10/02 18:06:50 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/ioctl.h>
# include <limits.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct			s_lserror
{
	int					type;
	int					exit_status;
	int					printed;
	char				*path;
	struct s_lserror	*next;
}						t_lserror;

typedef struct			s_lsfilestat
{

	char				aut[12];
	int					hardlink;
	char				*user_name;
	char				*group_name;
	long				size;
	long				date;
	char				*symlink;
	long				blocks;
	unsigned int		major;
	unsigned int		minor;
	char				*xattr;
	ssize_t				xattr_size;
	int					user_alloc;
}						t_lsfilestat;

typedef struct			s_lsdata
{
	int					rr	: 1;
	int					a	: 1;
	int					r	: 1;
	int					t	: 1;
	int					at	: 1;
	int					display_f;
	int					win_w;
	t_lserror			*errors;
	char				*prog_name;
	int					pad;
	int					param_nb;
	int					type;
}						t_lsdata;

typedef struct			s_lsfile
{
	char				*name;
	char				type;
	char				end : 1;
	t_lsfilestat		*info;
	char				*path;
	int					perm;
}						t_lsfile;

int						ft_msort(char **tab, int l, int r, int order);
int						ft_get_file_stats(t_lsfile *file);
t_lsfile				*ft_sort_alpha(t_lsfile *file, t_lsdata *data, int i);
t_lsfile				*ft_sort_time(t_lsfile *file, t_lsdata *data,
		int i, int j);
int						ft_nmsort(long long *tab, int l, int r, int order);
int						ft_printl(t_lsfile *file, t_lsdata *data);
int						ft_multi_display(t_lsfile *file, int win_w);
void					ft_single_print(t_lsfile *file);
int						ft_ls(t_lsfile *file, t_lsdata *data, t_lsfile *parent,
		char dir);
void					ft_print_dir(t_lsfile *file, t_lsdata *data,
		t_lsfile *parent, char total);
t_lsfile				*ft_store_files(t_lsfile *parent, t_lsdata *data);
void					ft_clean(t_lsfile *file);
int						ft_error_handle(t_lsdata *data, int type,
		char *path, int status);
int						ft_error_dump(t_lsdata *data);
int						ft_check_dir_perm(t_lsfile *dir, t_lsdata *data);
void					ft_display_error(t_lsdata *data, t_lserror *error);
int						get_options(char **av, int ac, t_lsdata **data);
t_lsfile				*ft_get_params(char **av, int ac, int i,
		t_lsdata *data);
int						ft_tabsplit(t_lsfile **files, t_lsfile **dirs,
		t_lsdata *data);
void					ft_clean(t_lsfile *file);
void					ft_file_setup(t_lsfile *file);
int						ft_get_largest_str(char **tab, int size,
		int col_n, int col);
void					get_col_lengths(char **tab, int i, int col, int *col_l);
void					ft_clean_str_tab(char **tab);
void					display_perm_err(t_lsdata *data, char *name);
int						ft_file_copy(t_lsfile *param, t_lsfile *file);
char					*strip_name(char *path);
int						get_acl(char *file);
int						get_xattr(t_lsfilestat *info, char *path);
int						ft_ilen(intmax_t nb);
int						long_print(int tab[4], t_lsfile *file, char date[23]);
int						ft_symlink_param(t_lsfile *file);
int						ft_store_file_stats(t_lsfile *file, struct stat buf,
		char *path);
char					*join_file_names(char *file_path, char *file_name,
		char **dest);

#endif
