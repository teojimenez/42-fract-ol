# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 17:57:31 by teojimene         #+#    #+#              #
#    Updated: 2024/01/30 17:57:31 by teojimene        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror -Imlx

SRC = src/main.c src/init.c src/utils.c src/utils2.c \
		src/render.c src/render_extra.c src/events.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

# ? MAC
GNOME_FLAGS = -framework OpenGL -framework AppKit
GNOME_PATH = ./minilibx-mac/
MLX_PATH = $(GNOME_PATH)/libmlx.a

FLAGS = -I $(GNOME_PATH) -I includes/fractol.h $(CFLAGS)

all : _mlx $(NAME)

$(NAME) : $(OBJECTS) $(MLX_PATH) includes/fractol.h Makefile
	$(CC) $(FLAGS) $(OBJECTS) $(MLX_PATH) $(GNOME_FLAGS) -o $(NAME)

%.o : %.c includes/fractol.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean :
	make clean -C $(GNOME_PATH)
	rm -f $(OBJECTS)

fclean : clean
	make clean -C $(GNOME_PATH)
	rm -f $(NAME)

re : fclean all

_mlx :
	make -C $(GNOME_PATH)

.PHONY: all clean fclean re _mlx