#pragma comment(lib, "ws2_32.lib") 
#include <WinSock2.h>
#include <stdio.h>
#include <string.h>
//#include <windows.h>
//#include <process.h>
#define SERVER_ADDRESS "127.0.0.1"
#define PROTOPORT 5188//缺省协议端口号
#define QLEN 6//监听套接字的请求队列大小
int Clientfd;
struct sockaddr_in servaddr;             
char buf[1000];

DWORD WINAPI receive_client(LPVOID)    //接收数据的Windows线程
{
	while (1)
	{
		char buf[1000];
		if(recv(Clientfd, buf, strlen(buf), 0) > 0)
		{
			printf("server: %s\n",buf);
			continue;
		}
	}
	return 0;
}
     
int main()
{
	
	WSADATA wsa;
	//初始化套接字DLL
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("套接字初始化失败！");
			exit(-1);
	}

	Clientfd = socket(AF_INET, SOCK_STREAM, 0);    //创建套接字
	memset((char*) & servaddr, 0, sizeof(servaddr));   //将保存地址的server置为全0 
	servaddr.sin_family = PF_INET;              //声明地址格式是TCP/IP地址格式
	servaddr.sin_port = htons(PROTOPORT);                //服务器的端口号  
	servaddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);    //指明地址  
	connect(Clientfd, (struct sockaddr *)&servaddr, sizeof(SOCKADDR_IN));   //连接到服务器/
	printf("client-server connected!\n");
	HANDLE hThread = CreateThread(NULL, 0, receive_client, 0, 0, 0);      //创建接收线程

	while (1)
	{
		scanf("%s", &buf);
		send(Clientfd, buf, strlen(buf)+1, 0);
		if(strncmp(buf, "quit", 4) == 0)
        {
            closesocket(Clientfd);
        }
		memset(buf, NULL, 1000);
	}
	closesocket(Clientfd); 
	CloseHandle(hThread);
	return 0;
}
