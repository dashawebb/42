# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 18:23:58 by elchrist          #+#    #+#              #
#    Updated: 2018/12/21 17:59:20 by elchrist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = *.c
OBJ = *.o
HEADER = -I includes/
FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS) $(HEADER)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
