SRC = pipex.c \
pipex_utils.c
FILE = null

CC = clang
CFLAGS ?= -Wall -Wextra -Werror

NAME = pipex

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -fsanitize=address $(SRC) -o $@ -L. -lft

unit:
	clang $(FILE).c -L. -lft -o unit_out
	rm outfile.txt
	touch outfile.txt
	./unit_out file1.txt "grep a1" "wc -w" outfile.txt 

clean:


fclean:
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
