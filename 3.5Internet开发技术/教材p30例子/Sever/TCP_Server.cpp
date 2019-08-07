#pragma comment(lib, "ws2_32.lib") 
#include <winsock2.h>
#include <stdio.h>
#include <string.h>
//#include <windows.h>
//#include <process.h>
#define PROTOPORT 5188//监听套接字的缺省协议端口号
#define QLEN 6//监听套接字的请求队列大小

struct sockaddr_in clientaddr;
struct sockaddr_in servaddr;
int listenfd;
int clientfd;

DWORD WINAPI receive_server(LPVOID)
{
	while (1)
	{
		char buf[100];
		if (recv(clientfd, buf, strlen(buf)+1, 0) > 0)
		{
			printf("client:");
			fprintf(stderr, buf);
		}
	}
	return 0;
}

void main(int argc, char **argv)
{
	int port;
	char buf[100];
	memset((char*)& servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	//检查命令行参数，如果指定了就是用该端口号。否则使用缺省端口号
	if (argc > 1)
		port = atoi(argv[1]);
	else
		port = PROTOPORT;
	if (port > 0)
		servaddr.sin_port = htons(PROTOPORT);
	else
	{
		fprintf(stderr, "false port number%s\n", argv[1]);
		exit(1);
	}
	WSADATA wsa;
	//初始化套接字DLL
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("套接字初始化失败！");
			exit(-1);
	}
	//创建一个用于监听的流式套接字
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0)
	{
		fprintf(stderr, "socket creation failed\n");
		exit(1);
	}
	//将本地地址绑定到监听套接字
	bind(listenfd, (struct sockaddr *)& servaddr, sizeof(servaddr));
	//开始监听，并指定监听套接字请求队列的长度
	listen(listenfd, QLEN);
	HANDLE hThread = CreateThread(NULL, 0, receive_server, 0, 0, 0);
	while (1)
	{
		int alen = sizeof(sockaddr_in);
		clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &alen);
		printf("server-client connected!");
		scanf("%s",&buf);
		send(clientfd, buf, strlen(buf)+1, 0);
		if(strncmp(buf, "quit", 4) == 0)
        {
            closesocket(clientfd);
        }
	}
	closesocket(clientfd);
	CloseHandle(hThread);
}
