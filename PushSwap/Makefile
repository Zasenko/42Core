NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c stack_creater.c swap.c push.c rotate.c reverse_rotate.c \
sort.c stack_rotation.c arg_to_stack.c find_in_stack.c find_pos_in_b.c \
free.c ft_split.c moves_count.c rotate_to_top.c setter.c \
stack_operations.c check_arg.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f $(OBJ)
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re