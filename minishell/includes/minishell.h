/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:27:50 by pacharbo          #+#    #+#             */
/*   Updated: 2020/05/07 18:17:21 by pacharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define EXP_BSIZE	20
# include <sys/param.h>
# include <sys/stat.h>
# include <pwd.h>
# include "libft.h"
# include "ft_printf.h"

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

typedef struct		s_exp
{
	char			buf[EXP_BSIZE];
	int				i;
	int				quote;
	int				bs;
	int				assign;
	char			*param;
	char			*word;
	char			*res;
}					t_exp;

int					parser(t_msh *data);
void				ft_ex(char *error);
void				free_memory(t_msh *data);
char				*ft_getenv(t_env *env, char *name);
t_env				*ft_setenvlist(char **env);
/*
**			exp
*/
int					exp_main(t_msh *data, char **word, int assign);
int					parse_param_exp(t_msh *data, char **word, t_exp exp);
char				*resolve_parameter(t_msh *data, char *str);
void				init_exp(t_exp *exp);
void				find_tilde_exp(t_msh *data, char **word, t_exp exp);
void				find_tilde_exp_assign(t_msh *data, char **word, t_exp exp);
int					parse_tilde_exp(t_msh *data, char **string, t_exp *exp, int assign);
void				exp_substitute(t_exp *exp, char *str);
void				free_exp_content(t_exp *exp);
void				exp_flush_buf(t_exp *exp, char **str);
void				exp_add_to_buf(t_exp *exp, char **str, char **res);
/*
**			builtins
*/
void				ft_echo(char **args);
void				ft_env(t_msh *data);
int					ft_setenv(t_env *env, char *name, char *value);
int					ft_unsetenv(t_msh *data, char *name);
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
