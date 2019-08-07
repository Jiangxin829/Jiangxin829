#pragma comment(lib, "ws2_32.lib") 
#include <winsock2.h>
#include <stdio.h>
#include <string.h>
//#include <windows.h>
//#include <process.h>
#define PROTOPORT 5188//监听套接字的缺省协议端口号
#define QLEN 6//监听套接字的请求队列大小      

struct sockaddr_in clientaddr;
struct sockaddr_in servaddr;//(local);
int Listenfd;
int Clientfd;
char buf[1000];

DWORD WINAPI receive_server(LPVOID) //接收数据的Windows线程
{
	while (1)
	{    
		char buf[1000];
		if (recv(Clientfd, buf, strlen(buf), 0) > 0)
		{
			printf("client: %s\n",buf);
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
	Listenfd = socket(AF_INET, SOCK_STREAM, 0);       //创建服务器监听套节字
	servaddr.sin_family = AF_INET;                     //声明地址格式是TCP/IP地址格式
	servaddr.sin_port = htons(PROTOPORT);              //服务器的端口号 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);      //自动获取本机地址 
	
	bind(Listenfd, (struct sockaddr *)&servaddr, sizeof(SOCKADDR_IN));    //地址绑定到套接字
	listen(Listenfd, 1);                                               //监听开始
	int alen = sizeof(sockaddr_in);
	Clientfd = accept(Listenfd, (struct sockaddr *)&clientaddr, &alen);    //建立连接 
	printf("server-client accepted!\n");
	HANDLE hThread = CreateThread(NULL, 0, receive_server, 0, 0, 0);        //创建接收线程

	while (1)
	{
		//scanf("%s",&buf);
		//send(Clientfd, buf, strlen(buf)+1, 0);
		//if(strncmp(buf, "quit", 4) == 0)
        //{
        //    closesocket(Clientfd);
        //}
		scanf("%s", &buf);
		send(Clientfd, buf, strlen(buf)+1, 0);
		if(strncmp(buf, "quit", 4) == 0)
        {
            closesocket(Clientfd);
        }
		memset(buf, NULL, 1000);
	}
	closesocket(Clientfd);
	closesocket(Listenfd);
	CloseHandle(hThread);                           
	return 0;
}
