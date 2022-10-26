# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:28:48 by joalmeid          #+#    #+#              #
#    Updated: 2022/10/26 01:46:41 by joalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCS_SERVER = server.c utils.c

SRCS_CLIENT = client.c utils.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

SRCS_SERVER_BONUS = server_bonus.c utils_bonus.c

SRCS_CLIENT_BONUS = client_bonus.c utils_bonus.c

OBJS_SERVER_BONUS = ${SRCS_SERVER_BONUS:.c=.o}

OBJS_CLIENT_BONUS = ${SRCS_CLIENT_BONUS:.c=.o}

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
	rm -f server client server.o client.o utils.o server_bonus.o client_bonus.o utils_bonus.o

re:	fclean all

rebonus:	fclean bonus

bonus:		${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}
			${CC} ${CFLAGS} ${SRCS_SERVER_BONUS} -o ${SERVER}; ${CC} ${CFLAGS} ${SRCS_CLIENT_BONUS} -o ${CLIENT}

.PHONY: all clean fclean re bonus rebonus
