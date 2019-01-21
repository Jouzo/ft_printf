# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 13:08:40 by jdescler          #+#    #+#              #
#    Updated: 2019/01/21 13:20:56 by jdescler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Printf

SRCS =	src/main.c\
		src/ft_print.c\
		src/parsing.c\

OBJS = $(SRCS:.c=.o)

CC = gcc -g -Iincludes/

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

.PHONY: all lib clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C libft
	-rm -f $(OBJS)

fclean:clean
	@make fclean -C ./libft/
	-rm -f $(NAME)

re: fclean all
