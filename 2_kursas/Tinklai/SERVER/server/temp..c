//Required Headers
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GuessTheNumber.h"
#define buffSize 100
#define gameMaxValue 50
 
int main(int argc, char **argv){


	printf("Server init %d\n",argc);
    			
    int listen_fd, comm_fd; //file descriptors
	
    struct sockaddr_in servaddr; //struct for IP and Port Numbers
	
    listen_fd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET Address Family Internet Protocol v4 Addresses (safe option)
 
    bzero( &servaddr, sizeof(servaddr));//clean
 
    servaddr.sin_family = AF_INET;					//set addressing scheme
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);	//allow any ip to connect
    servaddr.sin_port = htons(PortNumber);				//listen on port (needs to match with client) htons - Host order network short
 
	//prepare to listen for connections
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));	
	//start listening (max connection request)
    listen(listen_fd, 10);	
		
		//accept connection or wait for connect, return file descriptor once connection established
		comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
		char str[buffSize];

		struct gameValues game = getNewGame(gameMaxValue);		
		strcpy(str,"Guess the number game\n");
		write(comm_fd,str,strlen(str)+1);
		bzero(str, buffSize); //Make buffer zero
		
		while(0 == game.endConnection){
			bzero(str, buffSize);
			read(comm_fd,str,buffSize);//Get max of 100 chars and from comm_fb and store to str
			printf("Recieved: %s\n",str);
			parseInput(&game,str);
			write(comm_fd, str, strlen(str) +1); // send response
			
		}
		bzero(str, buffSize);
	
		printf("Close conn\n");	
	
    return 0;
}
