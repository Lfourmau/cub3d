# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 10:11:37 by lfourmau          #+#    #+#              #
#    Updated: 2021/02/25 08:39:39 by lfourmau         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c parsing.c parsing_utils.c struct_manip.c free_funcs.c map_parsing_utils.c check_close_spawn.c

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
