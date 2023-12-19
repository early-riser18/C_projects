SRC = pipex.c \
pipex_utils.c
OBJ = ${SRC:%.c=%.o}
FILE = null

CC = clang
CFLAGS ?= -Wall -Wextra -Werror

NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(SRC) -o $@ -L. -lft

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -o $@ 



clean:
	rm ${OBJ}

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
