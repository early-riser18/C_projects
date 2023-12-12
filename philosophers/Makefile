file = null
SRC = ./philosophers.c \
philo_utils.c

OBJ = ${SRC:%.c=%.o}

NAME=philosophers

CC = clang
CFLAGS ?= -Wall -Wextra -Werror

all: ${NAME}

NAME: ${OBJ}
	$(CC) ${OBJ} -o $(NAME)
	make clean

%.o : %.c
	$(CC) -c $< -o $@

clean:
	rm -f ${OBJ}