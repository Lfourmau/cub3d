# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 10:11:37 by lfourmau          #+#    #+#              #
#    Updated: 2021/05/07 08:01:42 by lfourmau         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = 	main.c \
		parsing/parsing.c \
		parsing/parsing_utils.c \
		parsing/struct_manip.c \
		parsing/free_funcs.c \
		parsing/map_parsing_utils.c \
		parsing/check_close_spawn.c \
		parsing/check_close_spawn_utils.c \
		parsing/check_pcub.c \
		window_prog.c \
		print_minimap.c \
		print_minimap_utils.c \
		mathematics.c \
		moove_funcs.c \
		raycasting.c \
		raycasting_utils.c \
		render_textures.c \
		render_sprites.c \
		render_sprites_utils.c \
		bitmap.c \
		sides.c \

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
