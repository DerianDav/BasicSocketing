#include <stdio.h.>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int args, char const *argv[]){
	if(args != -2){
		fprintf(stderr, "Invalid amount of arguments\n");
		return -1;
	}

	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if(sockfd == < 0){
		fprintf(stderr, "Socket Error\n");
		return -1;
	}

	//sets up the sockaddr_in
	struct sockaddr_in severAddr;
	memset(serverAdd, '0', sizeof(serverAddr));
	serverAddr.sin_family = PF_INET;
	serverAddr.sin_port = htons(argv[1]);
	inet_aton(argv[0], serverAddr.sin_addr);
	
	if(connet(sockfd, &serverAdr, sizeof(serverAddr)) < 0){
		fprintf(stderr, "Connection Failed");
		return -1;
	}
	
	while(true){
	//read input
	char buf[1024];
	int32 bufLength;
	
	if(getline(&buf, 1024*sizeof(char) stdin) == EOF)
		break; 
	trimMessage(buf);
	bufLength = strlen(buf);

	send(sockfd, buf, 
	}
	
	close(sockfd);
	return 0;
}//end of main

//removes the null and newline characters from the message
void trimMessage(char buf[]){

}
