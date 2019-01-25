# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:10:13 by jdescler          #+#    #+#              #
#    Updated: 2019/01/26 00:19:11 by jdescler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OPTION = ../includes/ft_printf.h

SRCS =	add_option.c\
		conversion.c\
		ft_bzero.c\
		ft_itoa_base.c\
		ft_itoc.c\
		ft_memcpy.c\
		ft_memset.c\
		ft_printstr.c\
		ft_putchar.c\
		ft_strchr.c\
		ft_strlen.c\
		ft_strrev.c\
		init_parse.c\
		ft_printf.c\
		ft_itoa_base.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra -I

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.PHONY: clean fclean re
clean:
	-rm -f $(OBJS)

fclean:clean
	-rm -f $(NAME)

re: fclean all
