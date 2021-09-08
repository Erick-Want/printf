# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 16:17:20 by ermatheu          #+#    #+#              #
#    Updated: 2021/09/08 10:40:49 by ermatheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		check_and_save.c \
		print_hex_pointer.c \
		print_storage.c \

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re