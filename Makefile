# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 15:22:34 by livsauze          #+#    #+#              #
#    Updated: 2024/07/05 12:39:04 by livsauze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC =	-I ./include/\

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread

UTILS = utils/utils.c utils/utils_libft.c
SRCS = ${UTILS} src/main.c src/ft_errors.c src/ft_init.c \
		src/ft_routine.c src/ft_dead.c
OBJS = ${SRCS:.c=.o}

%.o : %.c
		${CC} ${CFLAGS} ${INC} -c $< -o $@

${NAME} : ${OBJS}
		${CC} ${CFLAGS} ${INC} ${OBJS} -o ${NAME}
all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
		
