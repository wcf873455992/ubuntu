#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXBUFFERSIZE 256
#define SERVER_PORT 7780
#define CLIENT_PORT 8888
#define HOST_ADDR "192.168.40.100"

int main(int argc, char *argv[])
{
	int sockfd,n,flag;
	char recvbuff[MAXBUFFERSIZE];
	struct sockaddr_in servaddr;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("Socket created failed \n");
		return -1;
	}
	servaddr.sin_family 	= AF_INET;
	servaddr.sin_port	= htons(SERVER_PORT);
	servaddr.sin_addr.s_addr = inet_addr(HOST_ADDR);
	printf("connecting ...\n");
	flag = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(flag < 0){
		printf("connec server failed\n");
		return -1;
	}
	while((n = read(sockfd, recvbuff,MAXBUFFERSIZE)) > 0){
		recvbuff[n] = 0;
		fputs(recvbuff, stdout);
	}
	if(n < 0){
		printf("Read failed \n");
		return -2;
	}
	return 0;
}
