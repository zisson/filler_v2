# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsina <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/01 13:40:57 by zsina             #+#    #+#              #
#    Updated: 2016/04/01 13:41:01 by zsina            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c
SRC += ft_bzero.c
SRC += ft_isalnum.c
SRC += ft_isalpha.c
SRC += ft_isascii.c
SRC += ft_isblank.c
SRC += ft_isblank2.c
SRC += ft_isdigit.c
SRC += ft_ispace.c
SRC += ft_isprint.c
SRC += ft_itoa.c
SRC += ft_lst_push_back.c
SRC += ft_lstadd.c
SRC += ft_lstdel.c
SRC += ft_lstdelone.c
SRC += ft_lstiter.c
SRC += ft_lstmap.c
SRC += ft_lstnew.c
SRC += ft_memalloc.c
SRC += ft_memccpy.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memdel.c
SRC += ft_memmove.c
SRC += ft_memset.c
SRC += ft_putchar_fd.c
SRC += ft_putnchar_fd.c
SRC += ft_putchar.c
SRC += ft_putendl_fd.c
SRC += ft_putendl.c
SRC += ft_putnbr_fd.c
SRC += ft_putnbr.c
SRC += ft_putstr_fd.c
SRC += ft_putstr.c
SRC += ft_strcat.c
SRC += ft_strchr.c
SRC += ft_strclean.c
SRC += ft_strclr.c
SRC += ft_strcmp.c
SRC += ft_strcpy.c
SRC += ft_strdel.c
SRC += ft_strdup.c
SRC += ft_strequ.c
SRC += ft_striter.c
SRC += ft_striteri.c
SRC += ft_strjoin.c
SRC += ft_strlcat.c
SRC += ft_strlen.c
SRC += ft_strclean.c
SRC += ft_strmap.c
SRC += ft_strmapi.c
SRC += ft_strncat.c
SRC += ft_strncmp.c
SRC += ft_strncpy.c
SRC += ft_strndup.c
SRC += ft_strnequ.c
SRC += ft_strnew.c
SRC += ft_strnstr.c
SRC += ft_strrchr.c
SRC += ft_strrealloc.c
SRC += ft_strsplit_spc.c
SRC += ft_strsplit.c
SRC += ft_strstr.c
SRC += ft_strsub.c
SRC += ft_strtrim_spc.c
SRC += ft_strtrim.c
SRC += ft_tolower.c
SRC += ft_toupper.c
SRC += ft_swap.c
SRC += get_next_line.c
SRC += ft_getopt.c

SRC := $(addprefix libft/, $(SRC))

PTF = ft_printf.c
PTF += ft_vfdprintf.c
PTF += ft_fdprintf.c
PTF += ft_abs.c
PTF += ft_strtol.c
PTF += ft_strpos.c
PTF += ft_fill.c
PTF += ft_putnbrl_fd.c
PTF += ft_getargsize.c
PTF += ft_log.c
PTF += ft_printp.c
PTF += ft_printmod.c
PTF += ft_printsmall_di.c
PTF += ft_printsmall_s.c
PTF += ft_printsmall_b.c
PTF += ft_printsmall_x.c
PTF += ft_printsmall_o.c
PTF += ft_printsmall_u.c
PTF += ft_precisionwidth_tos.c
PTF += ft_precisionwidth_tocu.c
PTF += ft_precisionwidth_too.c
PTF += ft_precisionwidth_todi.c
PTF += ft_precisionwidth_tox.c
PTF += ft_calclen_s.c
PTF += ft_calclen_x.c
PTF += ft_calclen_p.c
PTF += ft_calclen_di.c
PTF += ft_calclen_o.c
PTF += ft_precisionwidth_top.c
PTF += ft_calclen_upocu.c
PTF += ft_calclen_x.c
PTF += ft_diezflag_tos.c
PTF += ft_diezflag_toupocu.c
PTF += ft_diezflag_too.c
PTF += ft_diezflag_todi.c
PTF += ft_diezflag_top.c
PTF += ft_diezflag_tox.c
PTF += ft_printc.c
PTF += ft_error.c
PTF += alloc.c
PTF += ft_isint.c
PTF += ft_isnumber.c
PTF += ft_atolli.c
PTF += ft_swapstr.c
PTF += ft_swapint.c

OBJECTS = $(SRC:.c=.o)
OBJECTS += $(PTF:.c=.o)

FLAGS = -Wall
FLAGS += -Werror
FLAGS += -Wextra

HEADER =

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "\033[1;31mCreating...\033[0m"
	@ar rc $@ $^
	@echo "\033[1;37mIndexing...\033[0m"
	@ranlib $@
	@echo "\033[0;32m" $(NAME) "Created !\033[0m"

%.o:%.c
	@$(CC) $(FLAGS) -c $< -o $@

allclean: fclean all clean

clean:
	@rm -f $(OBJECTS)
	@echo "\033[1;37m*.o delete objects files\033m"

fclean:
	@rm -f $(NAME) $(OBJECTS)
	@echo "\033[1;36m" $(NAME) "and *.o deleted\033[0m"

re: fclean all

.PHONY		:	all clean fclean re
