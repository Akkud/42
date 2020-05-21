NAME = libft.a


PRNTFSRC += conv.c
PRNTFSRC += conv_digit.c
PRNTFSRC += conv_digit2.c
PRNTFSRC += conv_e.c
PRNTFSRC += conv_f.c
PRNTFSRC += conv_g.c
PRNTFSRC += data.c
PRNTFSRC += display.c
PRNTFSRC += flag.c
PRNTFSRC += flag2.c
PRNTFSRC += ft_printf.c
PRNTFSRC += parser.c
PRNTFSRC += parser2.c

SRC += $(addprefix ft_printf/,$(PRNTFSRC))
SRC += ft_atoi.c
SRC += ft_memccpy.c
SRC += ft_putendl.c
SRC += ft_strcmp.c
SRC += ft_strlen.c
SRC += ft_strrchr.c
SRC += ft_bzero.c
SRC += ft_memchr.c
SRC += ft_putendl_fd.c
SRC += ft_strcpy.c
SRC += ft_strmap.c
SRC += ft_strsplit.c
SRC += ft_isalnum.c
SRC += ft_memcmp.c
SRC += ft_putnbr.c
SRC += ft_strdel.c
SRC += ft_strmapi.c
SRC += ft_strstr.c
SRC += ft_isalpha.c
SRC += ft_memcpy.c
SRC += ft_putnbr_fd.c
SRC += ft_strdup.c
SRC += ft_strncat.c
SRC += ft_strsub.c
SRC += ft_isascii.c
SRC += ft_memdel.c
SRC += ft_putstr.c
SRC += ft_strequ.c
SRC += ft_strncmp.c
SRC += ft_strtrim.c
SRC += ft_isdigit.c
SRC += ft_memmove.c
SRC += ft_putstr_fd.c
SRC += ft_striter.c
SRC += ft_strncpy.c
SRC += ft_tolower.c
SRC += ft_isprint.c
SRC += ft_memset.c
SRC += ft_strcat.c
SRC += ft_striteri.c
SRC += ft_strnequ.c
SRC += ft_toupper.c
SRC += ft_itoa.c
SRC += ft_putchar.c
SRC += ft_strchr.c
SRC += ft_strjoin.c
SRC += ft_strnew.c
SRC += ft_memalloc.c
SRC += ft_putchar_fd.c
SRC += ft_strclr.c
SRC += ft_strlcat.c
SRC += ft_strnstr.c
SRC += ft_lstnew.c
SRC += ft_lstdelone.c
SRC += ft_lstdel.c
SRC += ft_lstadd.c
SRC += ft_lstiter.c
SRC += ft_lstmap.c
SRC += ft_lstaddnext.c
SRC += ft_lstnewadd.c
SRC += ft_iferrfree.c
SRC += ft_swap.c
SRC += ft_itoa_base.c
SRC += ft_strlcpy.c
SRC += ft_print_words_tables.c
SRC += ft_lltoa_base.c
SRC += ft_ulltoa_base.c
SRC += ft_lltoa.c
SRC += ft_power.c
SRC += ft_sjoin1.c
SRC += ft_sjoin2.c
SRC += ft_sjoin3.c
SRC += get_next_line.c
SRC += ft_strcut.c
SRC += ft_strrep.c
SRC += ft_isdir.c
SRC += ft_clean_str_tab.c
SRC += ft_pathjoin.c
SRC += ft_strndup.c
SRC += ft_del_tab.c
SRC += ft_split.c
SRC += ft_isname.c

OPATHS += $(OPATH)ft_printf

INCLUDES += libft.h
INCLUDES += ft_printf.h

CC = clang
COMPILE = $(CC) -c
WFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(IPATH)
CFLAGS = $(WFLAGS) $(IFLAGS)

MKDIR = mkdir -p
CLEANUP = rm -rf

OPATH = objs/
SPATH = srcs/
IPATH = includes/

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SPATH),$(SRC))
OBJS = $(addprefix $(OPATH),$(OBJ))
INCS = $(addprefix $(IPATH),$(INCLUDES))

all: $(NAME)

$(NAME) : $(OPATHS) $(OBJS) Makefile
	ar rcs $@ $(OBJS)
	printf "$@ made.\n"

$(OBJS) : $(OPATH)%.o : $(SPATH)%.c $(INCS)
	$(COMPILE) $(CFLAGS) $< -o $@

$(OPATHS) :
	$(MKDIR) $@

clean:
	$(CLEANUP) $(OPATH)

fclean : clean
	$(CLEANUP) $(NAME)

re : fclean all

.PHONY: all clean fclean
