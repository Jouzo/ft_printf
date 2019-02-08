# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:10:13 by jdescler          #+#    #+#              #
#    Updated: 2019/02/08 12:47:36 by jdescler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OPTION = ../includes/ft_printf.h

SRCS =	add_option.c\
		conversion.c\
		init_parse.c\
		unicode.c\
		check_buf.c\
		ft_bzero.c\
		ft_itoc.c\
		ft_memcpy.c\
		ft_memset.c\
		ft_printstr.c\
		ft_putchar.c\
		ft_strchr.c\
		ft_strlen.c\
		ft_strrev.c\
		ft_printf.c\
		ft_all_toa_base.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -c -O3 -Wall -Werror -Wextra -I

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
