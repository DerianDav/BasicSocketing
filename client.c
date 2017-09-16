#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

void trimMessage(char buf[]);

int main(int args, char const *argv[]){
	
	if(args != 3){
		fprintf(stderr, "Invalid amount of arguments");
		return -1;
	}

	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		fprintf(stderr, "Socket Error\n");
		return -1;
	}

	//sets up the sockaddr_in
	struct sockaddr_in serverAddr = {0};
	//memset(&serverAddr, '0', sizeof(serverAddr));
	serverAddr.sin_family = PF_INET;
	serverAddr.sin_port = htons(stringToInt(argv[2]));
	inet_pton(PF_INET, argv[1], &serverAddr.sin_addr);
	
	if(connect(sockfd,(struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0){
		fprintf(stderr, "Connection Failed\n");
		return -1;
	}
	
	while(1){
	//read input
	char *buf = malloc(1024);
	size_t bufLength = 1024;
	if(getline(&buf,&bufLength, stdin) == EOF)
		break; 
	trimMessage(buf);
	bufLength = strlen(buf) -1;

	send(sockfd,(int32_t *) &bufLength , 4, 0);
	send(sockfd, buf, bufLength, 0); 
	}
	
	close(sockfd);
	return 0;
}//end of main

//removes the null and newline characters from the message
void trimMessage(char buf[]){
	if(buf[strlen(buf)-2] == '\n')
		buf[strlen(buf)-2] = '\0';
}

//converts a string of numbers into an integer
int stringToInt(char string[]){
	int ret = 0;
	int index;
	int indexFromLast = 0;
	for(index = strlen(string)-1; index >= 0; index--, indexFromLast++)
		ret += ((string[index]-'0') * (int)pow(10,indexFromLast));
	return ret;
}
