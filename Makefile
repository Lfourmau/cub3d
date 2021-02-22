# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 10:11:37 by lfourmau          #+#    #+#              #
#    Updated: 2021/02/22 11:33:15 by lfourmau         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c parsing.c parsing_utils.c struct_manip.c parse_map.c

OBJS = $(SRCS:.c=.o)

LIBS = libft.a libmlx.dylib

all : $(NAME)

%.o : %.c cub3d.h
	gcc -c -Wall -Werror -Wextra $< -o $(<:.c=.o) -g

$(NAME) : $(OBJS) $(SRCS) 
	cd libft && make bonus && cd ../mlx && make && cd ..
	mv libft/libft.a . && mv mlx/libmlx.dylib .
	gcc -Wall -Werror -Wextra -o cub3d $(LIBS) $(SRCS) -g

clean : 
	rm -f $(OBJS)
	cd libft && make clean && cd ../mlx && make clean

fclean : clean
	rm -f $(NAME) $(LIBS)

re : fclean all

.PHONY : all clean fclean re
