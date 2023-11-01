SRC = ./ft_printf.c \
./ft_printf_itoa.c \
./ft_printf_dtoa.c \
./ft_printf_itoh.c \


file = null

CC = clang
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a
OBJ = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	make clean

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
