file = null
SRC = ./philo.c \
philo_utils.c

OBJ = ${SRC:%.c=%.o}

NAME = philo

CC = clang
CFLAGS ?= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: $(OBJ)
	$(CC) -fsanitize=address $(OBJ) -L. -o $@
	make clean

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -o $@ -pthread

clean:
	rm -f $(OBJ)

fclean:
	rm $(NAME)

re: fclean all