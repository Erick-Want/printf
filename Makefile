# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 09:01:15 by ermatheu          #+#    #+#              #
#    Updated: 2021/09/23 15:01:02 by ermatheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME	= libftprintf.a

# CC		= clang

# OBJS		= ${SRCS:.c=.o}

# CFLAGS	= -Wall -Wextra -Werror

# SRCS	=	ft_printf.c \
# 		check_and_save.c \
# 		print_hex_pointer.c \
# 		print_storage.c \
# 		general_flags.c \
# 		print_flags.c \
# 		print_utils.c

# all: ${NAME}

# ${NAME} : ${OBJS} libft
# 	cp ./libft/libft.a $(NAME)
# 	ar -rcs $(NAME) $(OBJS)

# %.o: %.c
# 	${CC} -c ${CFLAGS} $< -o $@

# libft:
# 	make all -C ./libft

# bonus: all

# clean:
# 	rm -f ${OBJS}
# 	make clean -C ./libft

# fclean: clean
# 	rm -f ${NAME}
# 	make fclean -C ./libft

# re: fclean all libftre

# libftre:
# 	make re -C ./libft

# .PHONY: all libft clean fclean re libftre

NAME = libftprintf.a

LIBFT_DIR = ./libft

LIBFT = libft

CFLAGS = -Wall -Werror -Wextra

CC = clang

SRCS =	ft_printf.c \
		ft_check_and_save.c \
		ft_print_hex_pointer.c \
		ft_print_storage.c \
		ft_general_flags.c \
		ft_print_flags.c \
		ft_print_utils.c \
		ft_general_flag_s.c \
		ft_general_flag_d.c \
		ft_flag_width.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	cp ./libft/libft.a $(NAME)
	ar rc ${NAME} ${OBJS}

${LIBFT}:
	make all -C ${LIBFT_DIR}

bonus: all

clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all libft clean fclean re