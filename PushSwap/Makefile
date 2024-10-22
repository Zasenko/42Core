NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

SRC = main.c ft_split.c stack_creater.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	chmod +x $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# NAME = push_swap
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -Ilibft

# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a

# SRC = main.c stack_creater.c
# OBJ = $(SRC:.c=.o)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# all: $(LIBFT) $(NAME)

# $(NAME): $(OBJ)
# 	@echo "Compiling $(NAME)"
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
# 	chmod +x $(NAME)

# clean:
# 	rm -f $(OBJ)
# 	make clean -C $(LIBFT_DIR)

# fclean: clean
# 	rm -f $(NAME)
# 	make fclean -C $(LIBFT_DIR)

# re: fclean all

# .PHONY: all clean fclean re
