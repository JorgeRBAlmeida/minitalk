# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:28:48 by joalmeid          #+#    #+#              #
#    Updated: 2022/10/26 15:46:16 by joalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

NAME_B = minitalk_b

SRCS_SERVER = server.c utils.c

SRCS_CLIENT = client.c utils.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

BONUS_DIR = ./bonus/

SRCS_SERVER_BONUS = ${BONUS_DIR}server_bonus.c ${BONUS_DIR}utils_bonus.c

SRCS_CLIENT_BONUS = ${BONUS_DIR}client_bonus.c ${BONUS_DIR}utils_bonus.c

OBJS_SERVER_BONUS = ${SRCS_SERVER_BONUS:.c=.o}

OBJS_CLIENT_BONUS = ${SRCS_CLIENT_BONUS:.c=.o}

CLIENT = client

SERVER = server

CLIENT_BONUS = ${BONUS_DIR}client

SERVER_BONUS = ${BONUS_DIR}server

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	all

$(SERVER):	${OBJS_SERVER}
			${CC} ${CFLAGS} ${OBJS_SERVER} -o ${SERVER}

$(CLIENT):	${OBJS_CLIENT}
			${CC} ${CFLAGS} ${OBJS_CLIENT} -o ${CLIENT}

all:		$(SERVER) $(CLIENT)

clean:
	rm -f server client
	rm -f ${BONUS_DIR}server ${BONUS_DIR}client

fclean: clean
	rm -f server.o client.o utils.o
	rm -f ${BONUS_DIR}server_bonus.o ${BONUS_DIR}client_bonus.o ${BONUS_DIR}utils_bonus.o

re:	fclean all

rebonus:	fclean bonus

$(SERVER_BONUS):	${OBJS_SERVER_BONUS}
					${CC} ${CFLAGS} ${OBJS_SERVER_BONUS} -o ${BONUS_DIR}${SERVER}

$(CLIENT_BONUS):	${OBJS_CLIENT_BONUS}
					${CC} ${CFLAGS} ${OBJS_CLIENT_BONUS} -o ${BONUS_DIR}${CLIENT}

bonus:		$(SERVER_BONUS) $(CLIENT_BONUS)

.PHONY: all clean fclean re bonus rebonus
