# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 15:05:03 by lfourmau          #+#    #+#              #
#    Updated: 2021/02/22 16:34:12 by lfourmau         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
   	ft_isspace.c ft_atoi_base.c ft_itoa_base.c \
	ft_putnbr_base.c get_next_line.c

SRCSBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${SRCSBONUS:.c=.o}

RM = rm -f

_END = \033[0m
_DIM = \033[2m
_YELLOW = \033[33m
_GREEN = \033[92m
_RED = \033[91m
_ROSE = \033[95m
_CYAN = \033[96m

%.o : %.c libft.h
	@echo "${_GREEN}${_DIM} ✅ SUCCESS ✅  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ${_END}${_YELLOW}| $< |${_END}"
	@${CC} ${CFLAGS} -c $< -o $@ -g

$(NAME) : ${OBJS}
	@echo "${_GREEN} Action reussie pour  : ${_CYAN} $?"
	@ar -rc ${NAME} $?

all : ${NAME}

bonus : ${OBJSBONUS} ${OBJS}
	@echo "${_GREEN}Bonus ajoutes${_END}"
	@ar -rc ${NAME} ${OBJS} ${OBJSBONUS}

clean : 
	@echo "${_RED} Fichiers detruits${_END}"
	@${RM} ${OBJS} ${OBJSBONUS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
