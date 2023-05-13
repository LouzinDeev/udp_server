all:
	gcc server/main.c server/server.c server/command.c -o bin/server -lpthread -g
	gcc client/main.c client/client.c -o bin/client -lpthread -g
	