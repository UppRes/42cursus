NAME	=	philo
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	-g -lpthread -fsanitize=thread
SOURCES	=	$(shell find sources/*.c)

all	:	$(NAME)
	$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $(NAME)

clean	:
	rm -f $(NAME)

fclean	:	clean

re	:	fclean	all

.PHONY	: all $(NAME) clean fclean re
