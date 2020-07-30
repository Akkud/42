# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pacharbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 21:27:24 by pacharbo          #+#    #+#              #
#    Updated: 2018/11/07 21:46:45 by pacharbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = srcs/main.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) -Wall -Wextra -Werror $(SRC)

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
