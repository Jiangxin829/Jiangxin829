#pragma comment(lib, "ws2_32.lib") 
#include <winsock2.h>
#include <stdio.h>
#include <string.h>
//#include <windows.h>
//#include <process.h>
#define PROTOPORT 5188//�����׽��ֵ�ȱʡЭ��˿ں�
#define QLEN 6//�����׽��ֵ�������д�С

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
	//��������в��������ָ���˾����øö˿ںš�����ʹ��ȱʡ�˿ں�
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
	//��ʼ���׽���DLL
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("�׽��ֳ�ʼ��ʧ�ܣ�");
			exit(-1);
	}
	//����һ�����ڼ�������ʽ�׽���
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0)
	{
		fprintf(stderr, "socket creation failed\n");
		exit(1);
	}
	//�����ص�ַ�󶨵������׽���
	bind(listenfd, (struct sockaddr *)& servaddr, sizeof(servaddr));
	//��ʼ��������ָ�������׽���������еĳ���
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
