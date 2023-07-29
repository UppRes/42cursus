# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykuru <ykuru@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 12:42:47 by ykuru             #+#    #+#              #
#    Updated: 2022/09/01 18:28:51 by ykuru            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft/libft.a
NAME_C = client
NAME_S = server
FLAGS = -Wall -Wextra -Werror
FILE1 = client.c
FILE2 = server.c
CC = gcc

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) $(FILE1) $(NAME) -o $(NAME_C) 
	$(CC) $(FLAGS) $(FILE2) $(NAME) -o $(NAME_S)
 
clean:
	make clean -C libft
	rm -rf $(NAME_C) $(NAME_S)

fclean: 
	make fclean -C libft
	rm -rf $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all clean fclean re