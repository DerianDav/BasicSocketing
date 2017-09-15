#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		fprintf(stderr, "Socket Error");
		return -1;
	}

	struct sockaddr_in serverAddr;
	memset(serverAddr, '0', sizeof(serverAddr));
	serverAddr.sin_family = PF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = htons(arv[0]);

	if(bind(sock, &serverAddr, sizeof(serverAddr)) < 0){
		fprintf(stderr, "Bind Error");
		return -1;
	}
	
	if(listen(socket,5) < 0){
		fprintf(stderr, "Listen Error");
		return -1;
	}

	while(true){
		int newSock = accept(s, (struct sockaddr *) &sockAddr, 
			(socklen_t *) sizeof(sockAddr))
		if(newSock  < 0){
			fprintf(stderr, "Accept error");
			return -1;
		}
		
		char buf[1024];
		int = len;
		//while connection is open
		while(len = recv(newSock, buf, sizeof(buf), 0)){
			buf[1024] = '\0';
			printf("%s\n", buf);
		}
		
		close(n);

	}

}
