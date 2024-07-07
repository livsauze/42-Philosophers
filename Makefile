# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 15:22:34 by livsauze          #+#    #+#              #
#    Updated: 2024/07/07 19:53:06 by livsauze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***********Color Definition**************#
RED = \033[91m
YELLOW = \033[33m
GREEN = \033[92m
#******************************************#

NAME = philo

INC =	-I ./include/\

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread

UTILS = utils/utils.c utils/utils_libft.c
SRCS = ${UTILS} src/main.c src/ft_errors.c src/ft_init.c \
		src/ft_routine.c src/ft_dead.c
OBJS = ${SRCS:.c=.o}

%.o : %.c
		@${CC} ${CFLAGS} ${INC} -c $< -o $@

${NAME} : ${OBJS}
		@echo "$(YELLOW)...Compiling...\n"
		@${CC} ${CFLAGS} ${INC} ${OBJS} -o ${NAME}
		@echo "$(GREEN)Philo compiled ✅"
all : ${NAME}

clean :
		@echo "$(RED)Deleting object files\n"
		@rm -f ${OBJS}

fclean : clean
		@echo "$(RED)Deleting executable\n"
		@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
		
