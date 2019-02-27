# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 22:00:14 by elchrist          #+#    #+#              #
#    Updated: 2019/02/27 12:27:29 by creek            ###   ########.fr        #
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

OBJ   = $(SRC:.c=.o)

LIB_DIR  = libft/
LIBFT   = libft/libft.a
LIB_INCS  = libft/includes

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C $(LIB_DIR)

%.o: %.c $(HEADER) Makefile
	gcc $(FLAGS) -I$(LIB_INCS) -c $< -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
