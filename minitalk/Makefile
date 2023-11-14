CLIENT = client
SERVER = server

SRC_C = client.c
SRC_S = server.c 

OBJS_C := ${SRC_C:.c=.o}
OBJS_S := ${SRC_S:.c=.o}

CC = clang
CFLAGS ?= -Wall -Wextra -Werror

all:  $(CLIENT) $(SERVER)

%.o: %.c
	$(CC) -fsanitize=address $(CFLAGS) -c $<  -o $@

$(CLIENT): $(OBJS_C)
	$(CC) -fsanitize=address $(CFLAGS) $(OBJS_C) -L. -lft -o $(CLIENT)
	make clean
$(SERVER): $(OBJS_S)
	$(CC) -fsanitize=address $(CFLAGS) $(OBJS_S) -L. -lft -o $(SERVER)
	make clean
clean:
	rm -rf $(OBJS_C) $(OBJS_S)

fclean: clean
	rm -rf ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all clean fclean re