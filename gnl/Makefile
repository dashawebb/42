# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: creek <creek@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:13:44 by creek             #+#    #+#              #
#    Updated: 2019/01/20 15:00:16 by creek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./ft_bzero.c \
./ft_isalnum.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_memcpy.c \
./ft_memccpy.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_memset.c \
./ft_strcat.c \
./ft_strchr.c \
./ft_strcmp.c \
./ft_strcpy.c \
./ft_strdup.c \
./ft_strlcat.c \
./ft_strlen.c \
./ft_strncat.c \
./ft_strncmp.c \
./ft_atoi.c \
./ft_strncpy.c \
./ft_strnstr.c \
./ft_strrchr.c \
./ft_strstr.c \
./ft_tolower.c \
./ft_toupper.c \
./ft_memalloc.c \
./ft_memdel.c \
./ft_strnew.c \
./ft_strdel.c \
./ft_strclr.c \
./ft_striter.c \
./ft_striteri.c \
./ft_strmap.c \
./ft_strmapi.c \
./ft_strequ.c \
./ft_strnequ.c \
./ft_strsub.c \
./ft_strjoin.c \
./ft_strtrim.c \
./ft_strsplit.c \
./ft_itoa.c \
./ft_putchar.c \
./ft_putstr.c \
./ft_putendl.c \
./ft_putnbr.c \
./ft_putchar_fd.c \
./ft_putstr_fd.c \
./ft_putendl_fd.c \
./ft_putnbr_fd.c \
./ft_lstnew.c \
./ft_lstdelone.c \
./ft_lstdel.c \
./ft_lstadd.c \
./ft_lstiter.c \
./ft_lstmap.c

OBJ=$(SRCS:.c=.o)
HDR = includes/
FLAGS = -Wall -Werror -Wextra

.PHONY: all fclean clean re
	
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -I $(HDR) -c $^ -o $@

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
