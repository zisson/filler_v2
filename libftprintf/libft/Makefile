# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsina <zsina@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:53:08 by zsina             #+#    #+#              #
#    Updated: 2015/11/12 12:29:40 by zsina            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

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

OBJECTS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall
FLAGS += -Werror
FLAGS += -Wextra

HEADER =

all: $(NAME)

$(NAME):
	@echo "\033[1;35mCreating...\033[0m"
	@$(CC) $(FLAGS) -c $(SRC) $(HEADER)
	@ar rc $(NAME) $(OBJECTS)
	@echo "\033[1;38mIndexing...\033[0m"
	@ranlib $(NAME)
	@echo "\033[3;34mLibft.a Created !\033[0m"

allclean: fclean all clean

clean:
	@rm -f $(OBJECTS)
	@echo "\033[1;37m*.o delete objects files\033[0m"

fclean:
	@rm -f $(NAME) $(OBJECTS)
	@echo "\033[1;37mLibft.a && *.o deleted\\033[0m"

re: fclean all
