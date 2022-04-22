# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 15:31:10 by Ghenaut-          #+#    #+#              #
#    Updated: 2022/04/22 22:58:33 by Ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: .c.o libft.a all clean fclean re

SRCS	= ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c ./srcs/ft_swap.c
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a


.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I ./includes

libft.a: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all