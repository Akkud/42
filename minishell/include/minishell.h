/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:27:50 by pacharbo          #+#    #+#             */
/*   Updated: 2019/11/18 18:58:33 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../ft_printf/include/ft_printf.h"
# include <sys/param.h>
# include <sys/stat.h>

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_msh
{
	char			*cwd;
	char			**input;
	t_env			*env;
}					t_msh;

char				*ft_getenv(t_env *env, char *name);
t_env				*ft_setenvlist(char **env, char *name, char *value);
int					ft_envaddnext(t_env *env, char *name, char *value);
int					cd_setenv(t_env *env, char *name, char *value);
int					ft_cd(char **str, t_msh *data);
char				cd_getopt(char **str, int *i);
int					cd_home(t_msh *data);
char				*cd_setcurpath(t_msh *data, char *opr);
int					cd_logically(t_msh *data, char *curpath, char *opr);
int					cd_change_directory(t_msh *data, char *curpath, char *opr, char *pwd);
int					cd_set_relativepath(t_msh *data, char *curpath, char *opr, char *pwd);
char				*cd_del_dotcomponents(char *curpath, char *opr);
int					check_chdir_errors(char **str, char *path, char *opr);
int					check_whole_path(char *path);
int					display_cd_errors(char *error);

#endif
