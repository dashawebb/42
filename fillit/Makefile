# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 22:00:14 by elchrist          #+#    #+#              #
#    Updated: 2019/02/25 13:16:54 by creek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c \
	solving.c \
	placing.c \
	validation.c \
	reading.c \
	functions.c \
	list_functions.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
# CFLAGS += -I libft/includes/
#FLAGS = -Wall -Wextra -Werror
LIBFLAGS = -L libft/ -lft
HEADER = fillit.h
LIBFT = libft/
LIBINCLUDES = -I libft/includes

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT)

%.o: %.c
	gcc -c $(FLAGS) $(LIBINCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBINCLUDES) $(LIBFLAGS)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
