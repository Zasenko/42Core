NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c ft_split.c stack_creater.c \
swap.c push.c rotate.c reverse_rotate.c \
sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	chmod +x $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re