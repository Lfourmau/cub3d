# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 10:11:37 by lfourmau          #+#    #+#              #
#    Updated: 2021/05/09 17:12:37 by loic             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = 	srcs/main.c \
		srcs/parsing/parsing.c \
		srcs/parsing/parsing_utils.c \
		srcs/parsing/struct_manip.c \
		srcs/parsing/free_funcs.c \
		srcs/parsing/map_parsing_utils.c \
		srcs/parsing/check_close_spawn.c \
		srcs/parsing/check_close_spawn_utils.c \
		srcs/parsing/check_pcub.c \
		srcs/raycast/window_prog.c \
		srcs/print/print_minimap.c \
		srcs/print/print_minimap_utils.c \
		srcs/raycast/mathematics.c \
		srcs/raycast/moove_funcs.c \
		srcs/raycast/raycasting.c \
		srcs/raycast/raycasting_utils.c \
		srcs/print/render_textures.c \
		srcs/print/render_sprites.c \
		srcs/print/render_sprites_utils.c \
		srcs/bitmap/bitmap.c \
		srcs/raycast/sides.c \

OBJS = $(SRCS:.c=.o)

LIBS = libft.a libmlx.dylib

CFLAGS = -Wall -Wextra -Werror # -O3

all : $(NAME)

%.o : %.c cub3d.h
	gcc -c $(CFLAGS) $< -o $(<:.c=.o) -g

$(NAME) : $(OBJS)
	cd libft && make bonus && cd ../mlx && make && cd ..
	mv libft/libft.a . && mv mlx/libmlx.dylib .
	gcc $(CFLAGS) -o cub3d $(LIBS) $(OBJS)

clean : 
	rm -f $(OBJS)
	cd libft && make clean && cd ../mlx && make clean

fclean : clean
	rm -f $(NAME) $(LIBS)

re : fclean all

.PHONY : all clean fclean re
