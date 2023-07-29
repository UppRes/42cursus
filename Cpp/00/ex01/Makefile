NAME	= main

CC		= c++ -std=c++98
CFLAGS	= -Wall -Werror -Wextra

SOURCES	= $(wildcard *.cpp)

all		: $(NAME)

$(NAME)	:
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean	:
	rm -f $(NAME)

fclean	: clean

re		: fclean all