NAME = fillit

LIB = cd ./libft && make

LIBA = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ./main.c \
	./check.c \
	./read.c \
	./solve.c \
	./square.c \
	./free.c \
	./utils.c

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME) : $(OBJ)
	$(LIB)
	$(CC) $(CFLAGS) $(SRC) ./libft/$(LIBA) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $?

clean:
	$(LIB) clean
	rm -f $(OBJ)

fclean : clean
	$(LIB) fclean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re
