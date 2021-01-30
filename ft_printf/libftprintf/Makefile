# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 12:17:34 by vjacob            #+#    #+#              #
#    Updated: 2021/01/30 19:18:44 by vjacob           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRC		= ft_printf.c ft_print_px.c ft_print_csper.c ft_parse_ops.c \
		ft_parse_input.c libft.c ft_print_du.c ft_itoa.c ft_utoa.c
				
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

.PHONY: clean fclean all re $(NAME)
