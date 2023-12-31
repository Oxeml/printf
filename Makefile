# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 19:29:30 by oemelyan          #+#    #+#              #
#    Updated: 2023/07/21 23:35:58 by oemelyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	ft_printf.c	\
			functions.c \
			functions2.c

OBJ			=	$(SRC:%.c=%.o)

CFLAGS			= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	@ar rc $(NAME) $(OBJ)

# bonus		:	$(OBJ)
# 	@ar rc $(NAME) $^

$(OBJ)		:	$(SRC)
	@cc $(CFLAGS) -c $^

clean		:
	@rm -f $(OBJ)

fclean		:	clean
	@rm -f $(NAME)

re			:	fclean all

.PHONY:		all clean fclean re