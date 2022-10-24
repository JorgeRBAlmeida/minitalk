# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:28:48 by joalmeid          #+#    #+#              #
#    Updated: 2022/10/24 20:18:40 by joalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCS_SERVER = server.c utils.c

SRCS_CLIENT = client.c utils.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

CLIENT = client

SERVER = server

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	${OBJS_SERVER} ${OBJS_CLIENT}
			${CC} ${CFLAGS} ${SRCS_SERVER} -o ${SERVER}; ${CC} ${CFLAGS} ${SRCS_CLIENT} -o ${CLIENT}

clean:
	rm server client 

fclean:
	rm -f server client server.o client.o utils.o

re:	fclean all


.PHONY: all clean fclean re
