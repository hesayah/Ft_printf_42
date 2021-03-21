# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 03:06:09 by hesayah           #+#    #+#              #
#    Updated: 2020/02/04 19:47:18 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_atoi.c ft_active_struc.c ft_g_putchar.c ft_itoa_base.c ft_lltoa.c \
ft_printf.c ft_tab_fonc.c ft_type_c_s_pct.c ft_type_d_i.c ft_type_p.c \
ft_type_u.c ft_type_x.c \

GCC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDE = ft_printf.h

OBJ = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(FLAGS) -c $(SRCS) -I $(INCLUDE)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all \
 	clean \
	