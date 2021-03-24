# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 10:11:37 by lfourmau          #+#    #+#              #
#    Updated: 2021/03/24 18:30:06 by loic             ###   ########lyon.fr    #
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
		mathematics.c \
		moove_funcs.c \
		raycasting.c \

OBJS = $(SRCS:.c=.o)

LIBS = libft.a libmlx.dylib

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

%.o : %.c cub3d.h
	gcc -c $(CFLAGS) $< -o $(<:.c=.o)

$(NAME) : $(OBJS) $(SRCS) 
	cd libft && make bonus && cd ../mlx && make && cd ..
	mv libft/libft.a . && mv mlx/libmlx.dylib .
	gcc $(CFLAGS) -o cub3d $(LIBS) $(SRCS)

clean : 
	rm -f $(OBJS)
	cd libft && make clean && cd ../mlx && make clean

fclean : clean
	rm -f $(NAME) $(LIBS)

re : fclean all

.PHONY : all clean fclean re
