# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 12:17:34 by vjacob            #+#    #+#              #
#    Updated: 2021/01/26 18:28:12 by vjacob           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRC		= libftprintf.c ft_printf.c ft_print_p.c ft_print_c_n_s.c ft_parse_ops.c \
		ft_parse_input.c libft.c
				
OBJ				= $(SRC:.c=.o)

RM				= rm -f *.o
GSS_FL			= gcc -Wall -Wextra -Werror  -c

all:	$(NAME)

$(NAME):	libftprintf.h $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c libftprintf.h
	$(GSS_FL) $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all re
