# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 15:42:13 by pacharbo          #+#    #+#              #
#    Updated: 2019/05/21 15:40:33 by pacharbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wextra -Wall -Werror

SRC		=	conv.c \
			conv_digit.c \
			conv_digit2.c \
			conv_e.c \
			conv_f.c \
			conv_g.c \
			data.c \
			display.c \
			flag.c \
			flag2.c \
			ft_printf.c \
			parser.c \
			parser2.c \

OBJ		=	$(SRC:.c=.o)

SDIR	=	src

ODIR	=	obj

SRCS	=	$(addprefix $(SDIR)/,$(SRC))

OBJS	=	$(addprefix $(ODIR)/,$(OBJ))

all : $(NAME)

$(NAME) : objdir $(OBJS)
	make -C Libft
	cp Libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

objdir :
	mkdir -p $(ODIR)

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $? -o $@

clean :
	make clean -C Libft
	rm -rf $(ODIR)

fclean : clean
	rm -f $(NAME)
	rm -f Libft/libft.a

re : fclean all
