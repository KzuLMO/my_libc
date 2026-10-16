NAME	= my_libc.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

SRC	= my_strlen.c \
	  my_strcpy.c \
	  my_strncpy.c \
	  my_strcat.c \
	  my_strncat.c \
	  my_strcmp.c \
	  my_strncmp.c \
	  my_strchr.c \
	  my_strrchr.c \
	  my_strstr.c \
	  my_memset.c \
	  my_memcpy.c \
	  my_memmove.c \
	  my_memcmp.c \
	  my_memchr.c \
	  my_strdup.c \
	  my_strtok.c \
	  my_strlcpy.c \
	  my_strlcat.c \
	  my_explicit_bzero.c \
	  my_reallocarray.c \
	  my_isalpha.c \
	  my_isdigit.c \
	  my_isalnum.c

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
