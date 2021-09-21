# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/05 15:01:38 by ermatheu          #+#    #+#              #
#    Updated: 2021/08/18 12:42:56 by ermatheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_strlen.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_bzero.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_atoi.c \
		ft_memset.c \
		ft_memchr.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_split.c \

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJS_BONUS = ${BONUS:.c=.o}

OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: ${OBJS_BONUS}
	ar rc ${NAME} ${OBJS_BONUS}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean re
