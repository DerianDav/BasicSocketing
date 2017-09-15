
client: client.c
	gcc -Wall -g -o lineSort client.c 

server: server.c
	gcc -Wall -g -o server server.c

clean:
	-rm server
	-rm client
