#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define LISTENQ 	5
#define MAXLINE 	512
#define HOST_ADDR	"192.168.40.100"
#define SERVER_PORT	7780

int main(int argc, char *argv[])
{
	int listenfd,flag,connfd;
	uint32_t ip;
	socklen_t len;
	struct sockaddr_in servaddr,cliaddr;
	char buff[MAXLINE];
	time_t ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == 0){
		printf("Socket created failed \n");
		return -1;
	}
	servaddr.sin_family	= AF_INET;
	servaddr.sin_port	= htons(SERVER_PORT);
	servaddr.sin_addr.s_addr= inet_addr(HOST_ADDR);
	flag = bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(flag < 0){
		printf("bind err %d \n",flag);
		return -1;
	}
	printf("listening ...\n");
	listen(listenfd, LISTENQ);
	while(1){
		len = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
		ip = cliaddr.sin_addr.s_addr;
//printf("connect from %s,port %d\n",inet_ntoa(cliaddr.sin_addr.s_addr),ntohs(cliaddr.sin_port));
		printf("connect from :%d.%d.%d.%d ,port:%d \n",ip&0xff,(ip&0xff00)>>8,(ip&0xff0000)>>16,(ip&0xff000000)>>24,cliaddr.sin_port);
		ticks = time(NULL);
		sprintf(buff, "%.24s\r\n",ctime(&ticks));
		write(connfd, buff, strlen(buff));
		close(connfd);
	}
	close(connfd);
	return 0;
}


