all:
	cc -Wall -Wextra -Werror -o server server.c ; ./server

client: 
	cc -Wall -Wextra -Werror -o client client.c; ./client
