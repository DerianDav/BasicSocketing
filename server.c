#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <math.h>

int main(int args, char const *argv[]){
	//get the server port from the command line
	if(args != 2){
		fprintf(stderr, "Invalid Amount of Arguments\n");
		return -1;
	}
	//transforms the port string into an int
	int serverPort = 0;
	int index;
	int indexFromLast = 0;
	for(index = strlen(argv[1]) - 1; index >= 0; index--, indexFromLast++){
		serverPort += ((argv[1][index] - '0') * (int)pow(10,indexFromLast));
	}
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		fprintf(stderr, "Socket Error\n");
		return -1;
	}

	struct sockaddr_in serverAddr;
	memset(&serverAddr, '0', sizeof(serverAddr));
	serverAddr.sin_family = PF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(serverPort);

	int opt = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
	
	if(bind(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0){
		fprintf(stderr, "Bind Error\n");
		return -1;
	}

	if(listen(sock,5) < 0){
		fprintf(stderr, "Listen Error\n");
		return -1;
	}

	int addLen = sizeof(serverAddr);
	while(1){
		int newSock = accept(sock, (struct sockaddr *) &serverAddr, (socklen_t *) &addLen);
		if(newSock  < 0){
			fprintf(stderr, "Accept Error\n");
			return -1;
		}
		
	
		int32_t len = 0;
		//while connection is open
		while(recv(newSock, &len, 32, 0) > 0){
			char buf[len];
			recv(newSock, buf, len, 0);
			buf[len] = '\0';
			printf("%d\n%s\n", len, buf);			
		}
		
		close(newSock);
		break;//erase to have the server waiting for another connection after the inital client exits
	}

}
