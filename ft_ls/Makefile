NAME		=	ft_ls

LIB			=	./libft

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

DFLAG		=	-g

INCLUDES	=	includes

S_DIR		=	src

O_DIR		=	obj

OBJ			=	$(SRC:.c=.o)

SRCS		=	$(addprefix $(S_DIR)/,$(SRC))

OBJS		=	$(addprefix $(O_DIR)/,$(OBJ))

SRC			=	error.c \
				acl.c \
				ft_ls.c \
				main.c \
				merge.c \
				merge2.c \
				multi_print.c \
				misc.c \
				misc2.c \
				params.c \
				stat.c \
				stat2.c \
				long_print.c \
				long_print2.c \
				single_print.c \
				options.c \
				split.c \
				symlink.c \
				store.c

all: $(NAME)

set_dflag:
	$(eval CFLAGS += $(DFLAG))

$(O_DIR)/%.o: $(S_DIR)/%.c
	$(CC) $(CFLAGS) -c $? -I$(INCLUDES) -o $@

$(NAME): $(OBJS)
	make -C $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)/libft.a -o $(NAME)

debug: set_dflag $(OBJS)
	make debug -C $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)/libft.a -o $(NAME)

clean:
	make clean -C $(LIB)
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	make fclean -C $(LIB)
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
