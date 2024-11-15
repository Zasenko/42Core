NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
      src/stack_creater.c \
      src/swap.c \
      src/push.c \
      src/rotate.c \
      src/reverse_rotate.c \
      src/sort.c \
      src/stack_rotation.c \
      src/arg_to_stack.c \
      src/find_in_stack.c \
      src/find_pos_in_b.c \
      src/free.c \
      src/ft_split.c \
      src/moves_count.c \
      src/rotate_to_top.c \
      src/setter.c \
      src/stack_operations.c

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re