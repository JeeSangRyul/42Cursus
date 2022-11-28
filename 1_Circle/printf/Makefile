# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 14:44:53 by sji               #+#    #+#              #
#    Updated: 2022/09/07 15:04:05 by sji              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
cc = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	  ft_printf.c \
	  ft_print_hex.c \
	  ft_itoa.c \
	  ft_print_nbr.c \
	  ft_print_str.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	ar crsu $(NAME) $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re