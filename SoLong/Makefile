NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c read_file.c str_map_check.c check_field.c check_path.c \
get_next_line_utils.c get_next_line.c ft_split.c

OBJ = $(SRC:%.c=%.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = $(MLX_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) -L/usr/lib -I$(MLX_INC) -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_INC) -O3 -c $< -o $@

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re