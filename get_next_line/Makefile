SRC = get_next_line.c \
get_next_line_utils.c \

OBJ = ${SRC:%.c=%.o}
LIB = libget_next_line.a

CC = clang
CFLAGS = -Wall -Werror -Wextra

file = null

all: $(OBJ) $(LIB)

$(LIB):	$(OBJ)
	ar rcs $(LIB) $(OBJ)
	make clean
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

unit: 
	$(CC) $(CFLAGS) -fsanitize=address -D BUFFER_SIZE=10 $(file).c  -L. -lget_next_line -o main
	./main
clean:
	rm	-rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re