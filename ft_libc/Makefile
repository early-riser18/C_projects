SRC = ./ft_bzero.c \
./ft_isalnum.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_memset.c \
./ft_strchr.c \
./ft_strlcat.c \
./ft_strlcpy.c \
./ft_strlen.c \
./ft_strncmp.c \
./ft_strrchr.c \
./ft_tolower.c \
./ft_toupper.c 

OBJ = $(SRC:%.c=%.o)

NAME = libft

CC = clang
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)
	ar rcs $(NAME).a *.o
	make clean

$(NAME): 
	$(CC) -c $(CFLAGS) $(SRC) 



clean: 
	rm  $(OBJ)
fclean:

re: 

