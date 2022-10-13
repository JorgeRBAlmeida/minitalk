SERVER = server

CLIENT = client

SRC = client.c server.c

OBJS = ${SRC:.c=.o}

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -rf

NAME = ${CLIENT}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): 

$(CLIENT):

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${CLIENT} ${SERVER}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY: all clean fclean re
