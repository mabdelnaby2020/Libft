# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelna <mabdelna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 20:07:31 by mabdelna          #+#    #+#              #
#    Updated: 2024/03/07 17:03:03 by mabdelna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)
INCLUDE = -I./include
RM = rm -rf

NAME = push_swap
CHECK = checker

SRCS = $(wildcard src/*.c utils/*.c)
CHECK_SRCS = $(wildcard utils/*.c) src/swap.c src/push.c src/rotat.c src/rev_rotat.c checker.c

OBJS = $(SRCS:.c=.o)
CHECK_OBJS = ${CHECK_SRCS:.c=.o}



all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS}  -o ${CHECK}

clean: 
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re


