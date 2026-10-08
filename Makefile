NAME	= my_libc.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

SRC	= my_strlen.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c my_libc.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
