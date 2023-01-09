# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jee <jee@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 18:32:23 by sji               #+#    #+#              #
#    Updated: 2023/01/08 16:38:25 by jee              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

CC					= cc
CFLAGS				= -Wall -Wextra -Werror
AR					= ar rcs
RM					= rm -f

MAND_DIR			= ./mandatory/

STACK_DIR			=	stack/
STACK_SRC			=	stack.c validate.c

OPERATOR_DIR		=	operator/
OPERATOR_SRC		=	operator.c push.c reverse_rotate.c rotate.c swap.c

SORT_DIR			=	sort/
SORT_SRC			=	hard_coding.c pivot.c sort_a_to_b.c sort_b_to_a.c

UTILS_DIR			=	utils/
UTILS_SRC			=	error.c ft_split.c utils.c

SRC					=	main.c\
						$(addprefix $(STACK_DIR), $(STACK_SRC))\
						$(addprefix $(UTILS_DIR), $(UTILS_SRC))\
						$(addprefix $(OPERATOR_DIR), $(OPERATOR_SRC))\
						$(addprefix $(SORT_DIR), $(SORT_SRC))


SRCS				=	$(addprefix $(MAND_DIR), $(SRC))

OBJS				=	$(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all


.PHONY	:	all clean fclean re