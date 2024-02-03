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

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=	
# -fsanitize=address

SRC = main.c init.c utils.c render.c events.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

# ? LINUX
# GNOME_FLAGS = -lXext -lX11 -lm -lbsd
# GNOME_PATH = ./minilibx-linux/
# MLX_PATH = $(GNOME_PATH)/libmlx.a

# ? MAC
GNOME_FLAGS = -framework OpenGL -framework Appkit -l z
GNOME_PATH = ./minilibx-mac/
MLX_PATH = $(GNOME_PATH)/libmlx.a

FLAGS = -I $(GNOME_PATH) $(CFLAGS)

all : _mlx $(NAME)

$(NAME) : Makefile $(OBJECTS) $(MLX_PATH)
	@$(CC) $(FLAGS) $(OBJECTS) $(MLX_PATH) $(GNOME_FLAGS) -o $(NAME)

%.o : %.c fractol.h Makefile
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C $(GNOME_PATH)
	@rm -f $(OBJECTS)

fclean : clean
	@make clean -C $(GNOME_PATH)
	@rm -f $(NAME)

re : fclean all

_mlx :
	@make -C $(GNOME_PATH)

.PHONY: all clean fclean re _mlx