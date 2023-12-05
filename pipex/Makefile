SRC = pipex.c \
pipex_utils.c
FILE = null

CC = clang
CFLAGS ?= -Wall -Wextra -Werror

NAME = pipex

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS)  $(SRC) -o $@ -L. -lft

unit:
	$(CC) $(CFLAGS)  $(SRC) -fsanitize=address -o $(NAME) -L. -lft



clean:


fclean:
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
