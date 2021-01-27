# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 17:09:22 by wtahm             #+#    #+#              #
#    Updated: 2021/01/27 08:28:49 by wtahm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC 		= parser.c process_u.c process_d_i.c process_p_x.c ft_printf.c process_c_s.c process_flags.c

GCC 		= gcc -Wall -Wextra -Werror -c

all:
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	$(MAKE) $(NAME)

OBJ =  $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	
%.o: %.c
	$(GCC) $< -o $@
	
clean:
	rm -f *.o
	$(MAKE) -C libft clean
	
fclean: 	clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	
re: 		fclean all

.PHONY: 	all clean fclean re $(NAME)