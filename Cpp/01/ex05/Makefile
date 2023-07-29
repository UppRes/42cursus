NAME	= main

CC		= c++ -std=c++98
CFLAGS	= -Wall -Wextra -Werror

SRCS	= $(wildcard *.cpp)

all:$(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean : clean

re: fclean all