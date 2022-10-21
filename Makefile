CLIENT: client

SERVER: server

CC: gcc

CFLAGS: -Wall -Wextra -Werror

all:
	${CC} ${CFLAGS} -o server server.c; ${CC} ${CFLAGS} -o client client.c; ./server

$(NAME): 
	cc -Wall -Wextra -Werror -o ${NAME} ${NAME}.c

clean:	${OUTPUT}
	rm server client

fclean:
	rm -f server client

re:	fclean all


.PHONY: all clean fclean re
