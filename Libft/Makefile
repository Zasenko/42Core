# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzasenko <dzasenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 11:49:09 by dzasenko          #+#    #+#              #
#    Updated: 2024/09/06 13:47:58 by dzasenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
ft_tolower.c ft_toupper.c ft_atoi.c ft_strnstr.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c \
ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
