# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 17:26:02 by nkertzma          #+#    #+#              #
#    Updated: 2018/12/22 16:44:56 by nkertzma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRCS_DIR = srcs
INCL_DIR = includes
LIBS_DIR = libft
FLAGS = -Wall -Wextra -Werror
LIBS = -L$(LIBS_DIR) -l$(L_FILE)
C_FILES = ft_print_col.c ls_error.c reader.c ft_print_tools.c main.c sorts.c \
					tools.c parser.c sorts2.c parse_tools.c reader1.c reader2.c
O_FILES = $(C_FILES:%.c=%.o)
L_FILE = ft

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(O_FILES)
	make -C $(LIBS_DIR)
	$(CC) -o $(NAME) $(FLAGS) $(O_FILES) $(LIBS)

$(O_FILES): $(addprefix $(SRCS_DIR)/, $(C_FILES))
	$(CC) -c $(FLAGS) -I$(INCL_DIR) $(addprefix $(SRCS_DIR)/, $(C_FILES))

clean:
	rm -rf $(O_FILES)
	make -C $(LIBS_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBS_DIR) fclean

re:	fclean all
