# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 05:47:36 by mrezki            #+#    #+#              #
#    Updated: 2023/11/08 06:54:21 by mrezki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_strlen.c \
	ft_toupper.c ft_tolower.c ft_memcpy.c \
	ft_memset.c ft_bzero.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memcmp.c \
	ft_memchr.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_substr.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

norm:
	@norminette $(SRCS) libft.h

re: fclean all

.PHONY: clean fclean all re norm
