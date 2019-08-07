#pragma comment(lib, "ws2_32.lib") 
#include <WinSock2.h>
#include <stdio.h>
#include <string.h>
//#include <windows.h>
//#include <process.h>
#define SERVER_ADDRESS "127.0.0.1"
#define PROTOPORT 5188//缺省协议端口号
#define QLEN 6//监听套接字的请求队列大小
struct sockaddr_in servaddr;
//struct sockaddr_in clientaddr;
int sockfd;

DWORD WINAPI receive_client(LPVOID)
{	
	while (1)
	{
		char buf[100];
		if (recv(sockfd, buf, strlen(buf)+1, 0) > 0)
		{
			printf("server:");
			fprintf(stderr, buf);
		}
	}
	//Sleep(1000);
	return 0;
}

int main()
{
	//int alen;
	char buf[100];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset((char*)& servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = PF_INET;
	servaddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	servaddr.sin_port = htons(PROTOPORT); 

	WSADATA wsa;
	//初始化套接字DLL
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("套接字初始化失败！");
			exit(-1);
	}
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	printf("client-server connected!");
	HANDLE hThread = CreateThread(NULL, 0, receive_client, 0, 0, 0);
	while (1)
	{
		
		scanf("%s",&buf);
		send(sockfd, buf, strlen(buf)+1, 0);
		if(strncmp(buf, "quit", 4) == 0)
        {
            closesocket(sockfd);
        }
	}
	closesocket(sockfd);
	CloseHandle(hThread);
	return 0;
}
