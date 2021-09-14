# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 16:17:20 by ermatheu          #+#    #+#              #
#    Updated: 2021/09/14 13:13:17 by ermatheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = ./libft

LIBFT = ./libft/libft.a

SRCS = ft_printf.c \
		check_and_save.c \
		print_hex_pointer.c \
		print_storage.c \
		general_flags.c \
		print_flags.c

OBJS = ${SRCS:.c=.o}

${LIBFT}:
	make all -C ${LIBFT_DIR}

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: all

clean:
	rm -rf ${OBJS}
	make -C ${LIBFT_DIR} clean

fclean: clean
	rm -rf ${NAME}
	make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re