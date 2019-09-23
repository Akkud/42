# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guaubret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 17:02:43 by guaubret          #+#    #+#              #
#    Updated: 2019/09/01 08:11:19 by guaubret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

FT_PRINTF		=	ft_printf

LIBFT_PRINTF	=	$(FT_PRINTF)/libftprintf.a

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

DFLAG			=	-g

INCLUDES		=	includes

S_DIR			=	src

O_DIR			=	obj

SRC				=	ft_atoi.c \
					ft_bzero.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl.c \
					ft_putendl_fd.c \
					ft_putnbr.c \
					ft_putnbr_fd.c \
					ft_putstr.c \
					ft_putstr_fd.c \
					ft_strcat.c \
					ft_strchr.c \
					ft_strclr.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strdel.c \
					ft_strdup.c \
					ft_strequ.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strnequ.c \
					ft_strnew.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtrim.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_swap.c \
					ft_strnlen.c \
					ft_sqrt.c \
					ft_sort_integer_table.c \
					ft_strlcpy.c \
					ft_islower.c \
					ft_isupper.c \
					ft_strcapitalize.c \
					ft_isspace.c \
					ft_fddel.c \
					get_next_line.c \
					ft_strclnjoin.c \
					ft_itoa_base.c \
					ft_utoa_base.c \
					ft_power.c \
					ft_strlclnjoin.c \
					ft_strrclnjoin.c \
					ft_ftoa.c \
					ft_strclnsub.c \
					ft_modf.c \
					ft_fcvt.c \
					ft_strichr.c \
					ft_wcharlen.c \
					ft_wstrlen.c \

OBJ		=	$(SRC:.c=.o)

SRCS	=	$(addprefix $(S_DIR)/,$(SRC))

OBJS	=	$(addprefix $(O_DIR)/,$(OBJ))

all: $(NAME)

set_dflag:
	$(eval CFLAGS += $(DFLAG))

$(O_DIR)/%.o: $(S_DIR)/%.c
	$(CC) $(CFLAGS) -c $? -I$(INCLUDES) -o $@

$(NAME): $(OBJS)
	make -C $(FT_PRINTF)
	cp $(LIBFT_PRINTF) $(NAME)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

debug : set_dflag $(OBJS)
	make debug -C $(FT_PRINTF)
	cp $(LIBFT_PRINTF) $(NAME)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	make clean -C $(FT_PRINTF)
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	make fclean -C $(FT_PRINTF)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
