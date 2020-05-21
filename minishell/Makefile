NAME = minishell

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
SRC += exec.c
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
WFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(IPATH) -I $(LIPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)

MKDIR = mkdir -p
CLEANUP = rm -rf

OPATH = objs/
SPATH = srcs/
IPATH = includes/
LPATH = libft/
LIPATH = libft/includes/
LIB = $(LPATH)libft.a

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SPATH),$(SRC))
OBJS = $(addprefix $(OPATH),$(OBJ))
INCS = $(addprefix $(IPATH),$(INCLUDES))

all : $(NAME)

$(NAME) : lib $(OPATHS) $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(LIB)

$(OBJS) : $(OPATH)%.o : $(SPATH)%.c $(INCS)
	$(COMPILE) $(CFLAGS) $< -o $@

$(OPATHS) :
	$(MKDIR) $@

lib :
	$(MAKE) -C $(LPATH)

clean :
	$(MAKE) -C $(LPATH) clean
	$(CLEANUP) $(OPATH)

fclean : clean
	$(MAKE) -C $(LPATH) fclean
	$(CLEANUP) $(OPATH)
	$(CLEANUP) $(NAME)

re : fclean all

.PHONY: all clean fclean
