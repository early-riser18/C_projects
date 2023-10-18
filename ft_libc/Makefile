SRC = ./ft_atoi.c \
./ft_bzero.c \
./ft_isalnum.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_memset.c \
./ft_strchr.c \
./ft_strlcat.c \
./ft_strlcpy.c \
./ft_strlen.c \
./ft_strncmp.c \
./ft_strnstr.c \
./ft_strrchr.c \
./ft_tolower.c \
./ft_toupper.c \
./ft_calloc.c \
./ft_strdup.c \
./ft_strjoin.c \
./ft_substr.c \
./ft_strtrim.c \
./ft_split.c \
./ft_putchar_fd.c \
./ft_putstr_fd.c \
./ft_putendl_fd.c \
./ft_putnbr_fd.c \
./ft_itoa.c \
./ft_striteri.c \
./ft_strmapi.c \


SRC_BONUS = ./ft_lstnew.c \
./ft_lstadd_front.c \
./ft_lstsize.c \
./ft_lstlast.c \
./ft_lstadd_back.c \
./ft_lstdelone.c \
./ft_lstclear.c \
./ft_lstiter.c \
./ft_lstmap.c

file = ft_bzero

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

NAME = libft.a

CC = clang
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean bonus fclean re

all: $(NAME) 


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	make clean


%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@


unit:
	$(CC) $(CFLAGS) $(file).c -L. -lft -o unit_out
	./unit_out

bonus: $(NAME) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)
	make clean

clean: 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

