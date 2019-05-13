#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: creek <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 19:39:19 by creek             #+#    #+#              #
#    Updated: 2019/05/13 22:02:15 by creek            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
SRC = ft_ls.c ft_rbtnew.c output.c sorting.c ft_rbtclr.c ft_rbtroot.c main.c rbt_add.c ft_rbtforeach.c
OBJ   = $(SRC:.c=.o)
LIB_DIR  = libft/
LIBFT   = -L./libft -lft
LIB_INCS  = -I libft/includes
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) -g -o $(NAME) $(OBJ) $(LIBFT) $(LIB_INCS)

$(LIBFT):
	make -C $(LIB_DIR)

%.o: %.c
	gcc $(FLAGS) $(LIB_INCS) -c $^ -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
