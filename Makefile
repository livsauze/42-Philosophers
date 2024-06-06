# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 15:22:34 by livsauze          #+#    #+#              #
#    Updated: 2024/06/06 20:32:28 by livsauze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

LINK = -Llibft -lft

INC =	-I ./include/\
		-I ./libft/\

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread -g

UTILS = 
SRCS = ${UTILS} src/main.c src/ft_errors.c
OBJS = ${SRCS:.c=.o}

%.o : %.c
		${CC} ${CFLAGS} ${INC} -c $< -o $@

${NAME} : ${OBJS}
		make -C libft/
		${CC} ${CFLAGS} ${INC} ${OBJS} ${LINK} -o ${NAME}
all : ${NAME}

clean :
		rm -f ${OBJS}
		make clean -C libft/

fclean : clean
		make fclean -C libft/
		rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
		
