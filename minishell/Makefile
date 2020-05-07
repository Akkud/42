NAME = minishell
NAMEDB = minishell_db

SRC += cd/ft_cd.c 
SRC += cd/ft_cd_core.c
SRC += cd/ft_cd2.c
SRC += cd/chdir_errors.c
SRC += cd/chdir_errors2.c
SRC += echo/echo.c 
SRC += env/env.c
SRC += exp/exp.c
SRC += exp/exp_tools.c
SRC += exp/parameter.c
SRC += exp/param_resolve.c
SRC += exp/tilde_exp.c
SRC += exp/tilde_assign.c
SRC += main.c
SRC += parser.c
SRC += tools.c

OPATHS += $(OPATH)cd
OPATHS += $(OPATH)echo
OPATHS += $(OPATH)env
OPATHS += $(OPATH)exp

INCLUDES += minishell.h

CC = clang
COMPILE = $(CC) -c
COMPILEDB = $(CC) -g3
WFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(IPATH) -I $(LIPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)
DBFLAGS = -fsanitize=address

MKDIR = mkdir -p
CLEANUP = rm -rf

OPATH = objs/
SPATH = srcs/
IPATH = includes/
LPATH = libft/
LIPATH = libft/includes/
LIB = $(LPATH)libft.a
LIBDB = $(LPATH)libftdb.a

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SPATH),$(SRC))
OBJS = $(addprefix $(OPATH),$(OBJ))
INCS = $(addprefix $(IPATH),$(INCLUDES))

all : $(NAME)

lib :
	$(MAKE) -C $(LPATH) clean
	mv -n libft/Makefile libft/Makefile_db
	-mv -n libft/Makefile_n libft/Makefile

$(NAME) : lib $(LIB) $(OPATHS) $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(LIB)

$(OBJS) : $(OPATH)%.o : $(SPATH)%.c $(INCS)
	$(COMPILE) $(CFLAGS) $< -o $@

$(OPATHS) :
	$(MKDIR) $@

$(LIB) :
	$(MAKE) -C $(LPATH)

libdb :
	$(MAKE) -C $(LPATH) clean
	mv -n libft/Makefile libft/Makefile_n
	-mv -n libft/Makefile_db libft/Makefile

$(LIBDB) :
	$(MAKE) -C $(LPATH)

debug : libdb $(LIBDB)
	$(COMPILEDB) $(DBFLAGS) $(CFLAGS) -o $(NAMEDB) $(SRCS) $(LIBDB)

clean :
	$(MAKE) -C $(LPATH) clean
	$(CLEANUP) $(OPATH)

fclean : clean
	$(MAKE) -C $(LPATH) fclean
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(NAMEDB)

re : fclean all

.PHONY: all clean fclean
