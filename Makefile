# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 18:31:08 by chheniqu          #+#    #+#              #
#    Updated: 2024/11/22 18:31:23 by chheniqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	push_swap

SRCS=	ft_check_error.c \
		utils.c \
		operations.c \

OBJECTS=	$(SRCS:.c=.o)

BONUS_OBJECTS=	$(BONUS:.c=.o)

HEADERS=	includes

CC=	cc

CFLAGS=	-Wall -Werror -Wextra -I $(HEADERS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME) : $(OBJECTS)
	@make -C ./libft --no-print-directory
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L./libft -lft

clean:
	rm -rf $(OBJECTS)
	@make clean -C ./libft --no-print-directory

fclean: clean
	rm -rf $(NAME)
	@make fclean -C ./libft --no-print-directory

re:	fclean all

.PHONY:	all clean fclean re
