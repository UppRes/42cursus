NAME	=	Fixed

CC		=	c++ -std=c++98
CFLAGS	=	-Wall -Wextra -Werror

SOURCES	=	$(wildcard *.cpp)

all		:	$(NAME)

$(NAME)	:	$(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean	:
	rm -f $(NAME)

fclean	:	clean

re		:	fclean all