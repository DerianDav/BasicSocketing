.PHONY : all clean

all: client server

client: client.c
	gcc client.c -lm -o client

server: server.c
	gcc server.c -lm -o server

clean:
	-rm server
	-rm client
