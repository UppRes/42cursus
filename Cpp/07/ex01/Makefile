NAME	= Test
CC		= g++ -std=c++98
CLAFGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard *.cpp)

all		: $(NAME)

$(NAME) :
		$(CC) $(CLAFGS) $(SRCS) -o $(NAME)

clean	:
		rm -rf  $(NAME)

fclean	: clean

re		: fclean all